/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:32:11 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/11 16:38:31 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_table *table, const char *action)
{
	long	timestamp;

	pthread_mutex_lock(&table->print_mutex);
	if (!simulation_ended(table) || is_death_msg)
	{
		timestamp = current_time_ms() - table->start_time;
		printf("%ld %d %s\n", timestamp, table->philo->id + 1, action);
	}
	pthread_mutex_unlock(&table->print_mutex);
}