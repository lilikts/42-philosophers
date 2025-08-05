/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:53:41 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/05 17:53:41 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_table	*table;
	t_philo	**philos;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	parse_input(&data, argc, argv);
	
	table = malloc(sizeof(t_table));
	if (!table)
	{
		handle_error("Failed to initailze table!");
		return (EXIT_FAILURE);
	}
	philos = create_philos(&table);
	if (!philos)
		return (EXIT_FAILURE);
	start_simulation(&table);
	cleanup(&table);
	return (EXIT_SUCCESS);
}
