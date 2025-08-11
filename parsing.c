/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:31:15 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/11 15:43:37 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	return (0);
}

t_data *parse_input(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		handle_error("Allocation failed", data, NULL);
	if (!valid_arguments(argc, argv))
		handle_error("Invalid arguments", data, NULL);
	if (data_init(data, argc, argv) != 0)
		handle_error("Initialization of data failed", data, NULL);
	if (!valid_input(data, argc))
		handle_error("Invalid Input", data, NULL);
	return (data);
}