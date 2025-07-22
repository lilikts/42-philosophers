/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:42:49 by lkloters          #+#    #+#             */
/*   Updated: 2025/07/22 16:49:36 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	valid_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		while(argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
bool	valid_values(t_data *data)
{
	if (data->philo_count < 1 || data->philo_count >= 200)
		return (false);
	if (data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (false);
	if (data->eating_count && data->eating_count <= 0)
		return (false);
	return (true);
}

bool	valid_logic(t_data *data)
{
	if (data->philo_count == 1)
		handle_error();
	if (data->time_to_die < data->time_to_eat + data->time_to_sleep)
		handle_error();
	if (data->eating_count && data->eating_count == 0)
		handle_error();
	return (true);
}
