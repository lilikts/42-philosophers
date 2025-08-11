/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:41 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/11 16:17:55 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_table	*table;

	if (argc < 5 || argc > 6)
		handle_error("Wrong number of arguments\n", NULL, NULL);
	data = parse_input(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	table = init_structs(data);
	if (!table)
		return (EXIT_FAILURE);
	start_simulation(data, table);
	cleanup(data, table);
	return (EXIT_SUCCESS);
}
