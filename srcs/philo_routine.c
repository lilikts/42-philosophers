/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:14:48 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/14 15:25:47 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%ld %d %s\n", timestamp(philo->table), philo->id,
		"has taken a fork");
	pthread_mutex_unlock(&philo->table->print_mutex);
	smart_sleep(philo->data->time_to_die, philo->table);
	pthread_mutex_unlock(philo->left_fork);
}

bool	check_death_flag(t_table *table)
{
	bool	is_dead;

	pthread_mutex_lock(&table->death_mutex);
	is_dead = table->philo_dead;
	pthread_mutex_unlock(&table->death_mutex);
	return (is_dead);
}

bool	is_philo_finished(t_philo *philo)
{
	bool	finished;

	pthread_mutex_lock(&philo->meal_mutex);
	finished = (philo->meals_eaten == philo->table->data->meals_to_eat);
	pthread_mutex_unlock(&philo->meal_mutex);
	return (finished);
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
