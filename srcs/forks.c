/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:45:12 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/14 14:31:47 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_one_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (!check_death_flag(philo->table))
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id,
			"has taken a fork");
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

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
	take_one_fork(philo, first_fork);
	take_one_fork(philo, second_fork);
}

// void take_forks(t_philo *philo)
// { 
// 	if (philo->id % 2 == 0)
// 	{
// 		pthread_mutex_lock(philo->right_fork);
// 		pthread_mutex_lock(&philo->table->print_mutex);
// 		printf("%ld %d %s\n", timestamp(philo->table), philo->id,
// 			"has taken a fork");
// 		pthread_mutex_unlock(&philo->table->print_mutex);
// 		pthread_mutex_lock(philo->left_fork);
// 		printf("%ld %d %s\n", timestamp(philo->table), philo->id,
// 			"has taken a fork");
// 		pthread_mutex_unlock(&philo->table->print_mutex);
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(philo->left_fork);
// 		printf("%ld %d %s\n", timestamp(philo->table), philo->id,
// 			"has taken a fork");
// 		pthread_mutex_unlock(&philo->table->print_mutex);
// 		pthread_mutex_lock(philo->right_fork);
// 		printf("%ld %d %s\n", timestamp(philo->table), philo->id,
// 			"has taken a fork");
// 		pthread_mutex_unlock(&philo->table->print_mutex);
// 	}
// }

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
