/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:22:05 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 12:36:13 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup_table(t_table *table)
{
	int			i;
	t_status	*status;

	if (!table)
		return ;
	status = table->status;
	if (table->fork_mutex && status && status->fork_status > 0)
	{
		i = 0;
		while (i < status->fork_status)
		{
			pthread_mutex_destroy(&table->fork_mutex[i]);
			i++;
		}
		free(table->fork_mutex);
	}
	if (table->status && table->status->death_log_status)
		pthread_mutex_destroy(&table->death_mutex);
	if (table->status && table->status->print_status)
		pthread_mutex_destroy(&table->print_mutex);
	if (table->status && table->status->meal_status)
		pthread_mutex_destroy(&table->meal_mutex);
}

void	cleanup(t_data *data, t_table *table)
{
	if (table)
	{
		free(table->philo);
		free(table->monitor);
		cleanup_table(table);
		free(table->status);
		free(table);
	}
	if (data)
		free(data);
}

void	handle_error(const char *msg, t_data *data, t_table *table)
{
	if (msg)
		printf("Error: %s!\n", msg);
	if (!table && !data)
		exit(EXIT_FAILURE);
	cleanup(data, table);
	exit(EXIT_FAILURE);
}
