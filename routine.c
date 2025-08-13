/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:14:48 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/13 17:05:40 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d %s\n", timestamp(philo->table), philo->id, "has taken fork");
	pthread_mutex_unlock(&philo->table->print_mutex);
	smart_sleep(philo->data->time_to_die, philo->table);
	pthread_mutex_unlock(philo->left_fork);
}

static bool is_dead(t_table *table, t_philo *philo)
{
	long	now;
	bool	dead;

	dead = false;
	now = get_time_in_ms();
	pthread_mutex_lock(&philo->meal_mutex);
	if (now - philo->last_meal >= table->data->time_to_die)
	{
		dead = true;
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, "died");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	if (dead)
	{
		pthread_mutex_lock(&table->death_mutex);
		table->philo_dead = true;
		pthread_mutex_unlock(&table->death_mutex);
		return (true);
	}
	return (false);
}

static void	is_full(t_table *table, t_philo *philo, long *philo_full)
{
	if (table->data->meals_to_eat <= 0)
		return ;
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->meals_eaten == table->data->meals_to_eat)
		(*philo_full)++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

static bool	all_full(t_table *table, int philo_full)
{
	if (philo_full == table->data->philo_count)
	{
		pthread_mutex_lock(&table->is_full_mutex);
		table->all_full = true;
		pthread_mutex_unlock(&table->is_full_mutex);
		return (true);
	}
	return (false);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->data->philo_count == 1)
	{
		handle_one_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(200);
	while (!check_death_flag(philo->table))
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		if (is_philo_finished(philo))
			break ;
		rest(philo);
		think(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;
	long	philo_full;

	table = (t_table *)arg;
	while (1)
	{
		philo_full = 0;
		i = 0;
		while (i < table->data->philo_count)
		{
			if (is_dead(table, &table->philo[i]))
				return (NULL);
			is_full(table, &table->philo[i], &philo_full);
			i++;
		}
		if (all_full(table, philo_full))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
