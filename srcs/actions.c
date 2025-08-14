/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:11:34 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/14 14:32:13 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, "is eating");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_in_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	smart_sleep(philo->data->time_to_eat, philo->table);
}

void	rest(t_philo *philo)
{
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id,
			"is sleeping");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	smart_sleep(philo->data->time_to_sleep, philo->table);
}

void	think(t_philo *philo)
{
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id,
			"is thinking");
		pthread_mutex_unlock(&philo->table->print_mutex);
		usleep(500);
	}
}
