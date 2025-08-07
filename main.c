/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:41 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/07 13:06:43 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
		handle_error("Wrong number of arguments\n", NULL, NULL, NULL);
	table = handle_input(argc, argv);
	if (!table)
		return (EXIT_FAILURE);
	print_table(table);
	start_simulation(table);
	cleanup(table->data, table, table->philo);
	return (EXIT_SUCCESS);
}
