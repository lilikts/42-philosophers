/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:00:40 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/06 20:50:55 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_forks(t_data *data, t_table *table)
{
	int	i;
	
	if (!data || !table)
		return (1);
	table->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	data_init(t_data *data, int argc, char **argv)
{
	if (!data)
		return (1);
	memset(data, 0, sizeof(*data));
	data->philo_count = safe_atol(argv[1]);
	data->time_to_die = safe_atol(argv[2]);
	data->time_to_eat = safe_atol(argv[3]);
	data->time_to_sleep = safe_atol(argv[4]);
	if (argc == 6)
		data->meals_to_eat = safe_atol(argv[5]);
	if (data->philo_count == -1 || data->time_to_die == -1 || \
		data->time_to_eat == -1 || data->time_to_sleep == -1 || \
		(data->meals_to_eat && data->meals_to_eat == -1))
		return (1);
	if (!valid_values(data))
		return (handle_error("Invalid input values!", data, NULL, NULL), 1);
	if (argc == 6 && data->meals_to_eat == 0)
		return (handle_error("Eating requirement needs to be more than 0!", data, NULL, NULL), 1);
	if (data->time_to_die < data->time_to_eat + data->time_to_sleep)
		return (handle_error("Invalid timing values!", data, NULL, NULL), 1);
	return (0);
}

static int	table_init(t_data *data, t_table *table)
{
	if (!data || !table)
		return (1);
	memset(table, 0, sizeof(*table));
	table->data = data;
	table->start_time = get_time_in_ms();
	if (table->start_time == -1)
		return (1);
	if (create_forks(data, table) != 0)
		return (1);
	if (pthread_mutex_init(&table->death_mutex, NULL) != 0)
			return (1);
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (1);
	return (0);
}

static int	philo_init(t_data *data, t_table *table, t_philo *philo)
{
	int	i;	

	if (!data || !table || !philo)
		return (1);
	i = 0;
	memset(philo, 0, sizeof(t_philo) * data->philo_count);
	while (i < data->philo_count)
	{
		philo[i].id = i;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = table->start_time;
		philo[i].is_dead = false;
		philo[i].left_fork = &table->forks[i];
		philo[i].right_fork = &table->forks[(i + 1) % data->philo_count];
		i++;
	}
	return (0);
}

t_table *parse_input(int argc, char **argv)
{	
	t_data *data;
	t_table	*table;
	t_philo	*philo;

	data = malloc(sizeof(t_data));
	table = malloc(sizeof(t_table));
	if (!data || !table)
		return (handle_error("Allocation failed!", NULL, NULL, NULL), NULL);
	if (!valid_arguments(argc, argv))
		return (handle_error("Invalid arguments!", data, table, NULL), NULL);
	if (data_init(data, argc, argv) != 0)
		return (handle_error("Initialization of data failed!", data, table, NULL), NULL);
	if (table_init(data, table) != 0)
		return (handle_error("Initialization of table failed!", data, table, NULL), NULL);
	philo = malloc(sizeof(t_philo) * data->philo_count);
	if (!philo)
		return (handle_error("Allocation failed!", data, table, philo), NULL);
	if (philo_init(data, table, philo) != 0)
		return (handle_error("Initialization of philo failed!", data, table, philo), NULL);
	return (table);
}
