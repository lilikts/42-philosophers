/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:22:05 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/07 12:38:45 by lkloters         ###   ########.fr       */
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

void	cleanup(t_data *data, t_table *table, t_philo *philo, t_monitor *monitor)
{
	free(philo);
	free(monitor);
	free(data);
	if (table)
		cleanup_table(table);
}

void	handle_error(const char *msg, void *data, void *table, void *philo, void *monitor)
{
	if (msg)
		printf("Error: %s!\n", msg);
	if (!table && !data && !philo && !monitor)
		exit(EXIT_FAILURE);
	cleanup(data, table, philo, monitor);
	exit(EXIT_FAILURE);
}