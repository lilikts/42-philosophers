/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:11:34 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 10:47:34 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->meals_eaten++;
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->table->meal_mutex);
	print_action(philo, "is eating");
	smart_sleep(philo->data->time_to_eat, philo->table);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	rest(t_philo *philo)
{
	print_action(philo, "is sleeping");
	smart_sleep(philo->data->time_to_sleep, philo->table);
}

void	think(t_philo *philo)
{
	print_action(philo, "is thinking");
}
