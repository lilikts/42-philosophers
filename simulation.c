/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:00:19 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 10:33:52 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_philo_threads(t_data *data, t_table *table)
{
	int	i;

	if (!table || !data || !table->philo)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&table->philo[i].philo_thread, NULL, philo_routine, &table->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	create_monitor_thread(t_data *data, t_table *table)
{
	if (!table || !data || !table->philo)
		return (1);
	if (pthread_create(&table->monitor->monitor_thread, NULL, monitor_routine, table) != 0)
		return (1);
	return (0);
}

static int	join_philo_threads(t_data *data, t_table *table)
{
	int	i;

	if (!table || !data || !table->philo)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_join(table->philo[i].philo_thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int join_monitor_thread(t_data *data, t_table *table)
{
    if (!table || !data || !table->philo)
		return (1);
    if (pthread_join(table->monitor->monitor_thread, NULL) != 0)
        return (1);
    return (0);
}

void	start_simulation(t_data *data, t_table *table)
{
	table->start_time = get_time_in_ms();
	if (create_philo_threads(data, table) != 0)
		handle_error("Failed to create philo threads", data, table);
	if (create_monitor_thread(data, table) != 0)
		handle_error("Failed to create monitor thread", data, table);
	if (join_philo_threads(data, table) != 0)
		handle_error("Failed to join philo threads", data, table);
	if (join_monitor_thread(data, table) != 0)
		handle_error("Failed to join monitor thread", data, table);
}
