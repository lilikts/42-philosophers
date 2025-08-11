/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:22:05 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/11 16:08:35 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup_table(t_table *table)
{
	int	i;

	if (!table)
		return ;
	if (table->forks)
	{
		i = 0;
		while (i < table->philo_count)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->death_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	free(table);
}

void	cleanup(t_data *data, t_table *table)
{
	if (table)
	{
		free(table->philo);
		free(table->monitor);
		free(table->status);
		cleanup_table(table);
	}
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