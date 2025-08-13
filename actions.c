/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:11:34 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/13 16:49:48 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;

	if (philo->left_fork < philo->right_fork)
	{
		first_fork = philo->left_fork;
        second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
        second_fork = philo->left_fork;
	}
	pthread_mutex_lock(first_fork);
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, "has taken fork");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	pthread_mutex_lock(second_fork);
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, "has taken fork");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meals_eaten++;
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meal_mutex);
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, "is eating");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	smart_sleep(philo->data->time_to_eat, philo->table);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	rest(t_philo *philo)
{
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, "is sleeping");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	smart_sleep(philo->data->time_to_sleep, philo->table);
}

void	think(t_philo *philo)
{
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, "is thinking");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
}
