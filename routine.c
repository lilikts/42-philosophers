/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:14:48 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/11 21:26:35 by lkloters         ###   ########.fr       */
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
	while (// is_dead flag is not true)
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		sleep(philo);
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