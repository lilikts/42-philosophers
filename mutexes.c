/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:32:11 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/13 16:35:29 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death_flag(t_table *table)
{
	bool	is_dead;	

	pthread_mutex_lock(&table->death_mutex);
	is_dead = table->philo_dead;
	// printf("Death flag: %d\n", is_dead);
	pthread_mutex_unlock(&table->death_mutex);
	return (is_dead);
}

bool	check_full_flag(t_table *table)
{
	bool	all_full;

	pthread_mutex_lock(&table->is_full_mutex);
	all_full = table->all_full;
	pthread_mutex_unlock(&table->is_full_mutex);
	return (all_full);
}

bool	is_philo_finished(t_philo *philo)
{
	bool	finished;

    pthread_mutex_lock(&philo->meal_mutex);
    finished = (philo->meals_eaten == philo->table->data->meals_to_eat);
    pthread_mutex_unlock(&philo->meal_mutex);
    return (finished);
}
