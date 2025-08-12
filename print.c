/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:32:11 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 11:16:20 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, const char *action)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!philo->table->monitor->philo_dead && \
		philo->table->monitor->philo_full < philo->data->philo_count)
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, action);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
