/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:14:48 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/11 21:51:28 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo->table, "has taken a fork");
	smart_sleep(philo->data->time_to_die, philo->table);
	pthread_mutex_unlock(philo->left_fork);
}

static bool	check_death(t_table *table)
{
	int	i;
	long	now;

	i = 0;
	while (i < table->data->philo_count)
	{
		now = get_time_in_ms();
		pthread_mutex_lock(&table->meal_mutex);
		if (now - table->philo[i].last_meal >= table->data->time_to_die)
		{
			pthread_mutex_lock(&table->print_mutex);
			if (!table->monitor->philo_dead)
			{
				print_action(table, "died");
				table->monitor->philo_dead = true;
			}
			pthread_mutex_unlock(&table->print_mutex);
			pthread_mutex_unlock(&table->meal_mutex);
			return (true);
		}
		pthread_mutex_unlock(&table->meal_mutex);
		i++;
	}
	return (false);
}

static bool check_all_full(t_table *table)
{
	int	i;
	long	full_count;

	if (table->data->meals_to_eat <= 0)
		return (false);
	i = 0;
	full_count = 0;
	while (i < table->data->philo_count)
	{
		pthread_mutex_lock(&table->meal_mutex);
		if (table->philo[i].meals_eaten >= table->data->meals_to_eat)
			full_count++;
		pthread_mutex_unlock(&table->meal_mutex);
		i++;	
	}
	if (full_count == table->data->philo_count)
		return (true);
	else
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
	while (!philo->table->monitor->philo_dead && \
		philo->table->monitor->philo_full < philo->data->philo_count)
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		rest(philo);
		think(philo);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		if (check_death(table))
			break ;
		if (check_all_full(table))
		{
			table->monitor->philo_full = table->data->philo_count;
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}