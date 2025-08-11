/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:14:48 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/11 16:47:53 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take(t_philo *philo)
{
	if (!philo)
		return ;
	
}

static void	think(t_philo *philo)
{
	print_action()
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(200);
	while (// is_dead flag is not true)
	{
		take(philo);
		eat(philo);
		release(philo);
		sleep(philo);
		think(philo);
	}
	return (NULL);
}


// void *philo_routine(void *arg)
// {
//     (void)arg; // unused parameter
//     // Simuliere Philosophenarbeit
//     sleep(1);
//     return NULL;
// }

// void *monitor_routine(void *arg)
// {
//     (void)arg; // unused parameter
//     // Simuliere Monitoring
//     sleep(1);
//     return NULL;
// }