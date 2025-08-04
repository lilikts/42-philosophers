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

void parse_input(int argc, char **argv, t_table *table)
{	
	data_init(table);
	if (!valid_arguments(argc, argv))
		handle_error("Invalid arguments!");
	table->philo_count = safe_atol(argv[1]);
	table->time_to_die = safe_atol(argv[2]);
	table->time_to_eat = safe_atol(argv[3]);
	table->time_to_sleep = safe_atol(argv[4]);
	if (argc == 6)
	table->meals_to_eat = safe_atol(argv[5]);
	if (table->philo_count == -1 || table->time_to_die == -1 || \
		table->time_to_eat == -1 || table->time_to_sleep == -1 || \
		table->time_to_sleep == -1 || (table->meals_to_eat && table->meals_to_eat == -1))
		return ;
	if (!valid_values(table))
		handle_error("Invalid input values!");
	if (argc == 6 && table->meals_to_eat == 0)
		handle_error("Eating requirement needs to be more than 0!");
	if (table->time_to_die < table->time_to_eat + table->time_to_sleep)
		handle_error("Invalid timing values!");
}
