/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:22:05 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/06 20:47:27 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup_data(t_data *data)
{
	if (!data)
		return ;
	free(data);
}

static void	cleanup_table(t_data *data, t_table *table)
{
	int	i;

	if (!table)
		return ;
	if (table->forks)
	{
		i = 0;
		while (i < data->philo_count)
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

static void	cleanup_philo(t_philo *philo)
{
	if (!philo)
		return ;
	free(philo);
}

void	cleanup(t_data *data, t_table *table, t_philo *philo)
{
	if (philo)
		cleanup_philo(philo);
	if (table)
		cleanup_table(data, table);
	if (data)
		cleanup_data(data);
}

void	handle_error(const char *msg, void *data, void *table, void *philo)
{
	if (msg)
		printf("Error: %s!\n", msg);
	cleanup(data, table, philo);
	exit(EXIT_FAILURE);
}