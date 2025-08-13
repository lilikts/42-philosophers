/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:15:55 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/13 17:40:54 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_forks(t_data *data, t_table *table)
{
	int	i;

	if (!data || !table || !table->status)
		return (1);
	table->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!table->fork_mutex)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&table->fork_mutex[i], NULL) != 0)
			return (1);
		table->status->fork_status++;
		i++;
	}
	return (0);
}
