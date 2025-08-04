/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:42:49 by lkloters          #+#    #+#             */
/*   Updated: 2025/07/30 10:42:29 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	valid_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

bool	valid_values(t_table *table)
{
	if (table->philo_count < 1 || table->philo_count >= 200)
		return (false);
	if (table->time_to_die <= 0 || table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		return (false);
	if (table->meals_to_eat && table->meals_to_eat <= 0)
		return (false);
	return (true);
}
