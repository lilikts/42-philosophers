/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:41 by lkloters          #+#    #+#             */
/*   Updated: 2025/07/30 13:29:06 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
	{
		handle_error("Invalid number of arguments!");
		return (EXIT_FAILURE);
	}
	table = malloc(sizeof(t_table));
	if (!table)
	{
		handle_error("Failed to initailze table!");
		return (EXIT_FAILURE);
	}
	parse_input(argc, argv, &table);
	philo = create_philos(&table);
	start_simulation(&table);
	cleanup(&table);
	return (0);
}
