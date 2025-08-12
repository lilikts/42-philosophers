/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:00:40 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 10:30:48 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	table_init(t_data *data, t_table *table, t_status *status)
{
	if (!data || !table || !status)
		return (1);
	memset(table, 0, sizeof(*table));
	table->data = data;
	table->status = status;
	table->start_time = get_time_in_ms();
	table->philo_count = table->data->philo_count;
	if (table->start_time == -1)
		return (1);
	if (create_forks(data, table) != 0)
		return (1);
	if (pthread_mutex_init(&table->death_mutex, NULL) != 0)
			return (1);
	table->status->death_log_status = 1;
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (1);
	table->status->print_status = 1;
	if (pthread_mutex_init(&table->meal_mutex, NULL) != 0)
		return (1);
	table->status->meal_status = 1;
	return (0);
}

static int	philo_init(t_table *table, t_philo *philo)
{
	int	i;	

	if (!table || !table->data || !philo)
		return (1);
	i = 0;
	while (i < table->data->philo_count)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = table->start_time;
		philo[i].is_dead = false;
		philo[i].left_fork = &table->fork_mutex[i];
		philo[i].right_fork = &table->fork_mutex[(i + 1) % table->data->philo_count];
		philo[i].table = table;
		philo[i].data = table->data;
		i++;
	}
	return (0);
}

static int	philo_and_monitor_init(t_table *table)
{
	if (!table || !table->data)
		return (1);
	t_philo	*philo;
	t_monitor *monitor;

	philo = malloc(sizeof(t_philo) * table->data->philo_count);
	monitor = malloc(sizeof(t_monitor));
	if (!philo || !monitor)
		return (1);
	memset(philo, 0, sizeof(t_philo) * table->data->philo_count);
	memset(monitor, 0, sizeof(t_monitor));
	if (philo_init(table, philo) != 0)
		return (1);
	table->philo = philo;
	table->monitor = monitor;
	table->monitor->philo_dead = false;
	table->monitor->philo_full = 0;
	return (0);
}

static int	status_init(t_status *status)
{
	if (!status)
		return (1);
	memset(status, 0, sizeof(t_status));
	return (0);
}

t_table *init_structs(t_data *data)
{
	t_table		*table;
	t_status	*status;

	if (!data)
		return (NULL);
	table = malloc(sizeof(t_table));
	status = malloc(sizeof(t_status));
	if (!table || !status)
		return (handle_error("Allocation failed", data, table), NULL);
	if (status_init(status) != 0)
		return (handle_error("Initialization of status failed", data, table), NULL);
	if (table_init(data, table, status) != 0)
		return (handle_error("Initialization of table failed", data, table), NULL);
	if (philo_and_monitor_init(table) != 0)
		return (handle_error("Initialization of philo and monitor failed", data, table), NULL);
	return (table);
}

// split philo and monitor init
