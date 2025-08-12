/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:42:49 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 12:24:53 by lkloters         ###   ########.fr       */
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

bool	valid_input(t_data *data, int argc)
{
	if (data->philo_count < 1 || data->philo_count >= 200)
		return (false);
	if (data->time_to_die <= 0 || data->time_to_eat <= 0 || \
		data->time_to_sleep <= 0)
		return (false);
	if (data->meals_to_eat && data->meals_to_eat <= 0)
		return (false);
	if (argc == 6 && data->meals_to_eat <= 0)
		return (false);
	return (true);
}
