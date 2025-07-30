/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:00:40 by lkloters          #+#    #+#             */
/*   Updated: 2025/07/30 13:24:32 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void parse_input(int argc, char **argv, t_data *data)
{	
	data_init(data);
	if (!valid_arguments(argc, argv))
		handle_error("Invalid arguments!");
	data->philo_count = safe_atol(argv[1]);
	data->time_to_die = safe_atol(argv[2]);
	data->time_to_eat = safe_atol(argv[3]);
	data->time_to_sleep = safe_atol(argv[4]);
	if (argc == 6)
	data->eating_count = safe_atol(argv[5]);
	if (data->philo_count == -1 || data->time_to_die == -1 || \
		data->time_to_eat == -1 || data->time_to_sleep == -1 || \
		data->time_to_sleep == -1 || (data->eating_count && data->eating_count == -1))
		return ;
	if (!valid_values(data))
		handle_error("Invalid input values!");
	if (argc == 6 && data->eating_count == 0)
		handle_error("Eating requirement needs to be more than 0!");
	if (data->time_to_die < data->time_to_eat + data->time_to_sleep)
		handle_error("Invalid timing values!");
}
