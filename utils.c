/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:15:55 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 10:34:23 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	safe_atol(char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (1);
	return (result);
}

int	create_forks(t_data *data, t_table *table)
{
	int	i;
	
	if (!data || !table || !table->status)
		return (1);
	table->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!table->fork_mutex)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&table->fork_mutex[i], NULL) != 0)
			return (1);
		table->status->fork_status++;
		i++;
	}
	return (0);
}

void	smart_sleep(long time_in_ms, t_table *table)
{
	long	start;
	
	start = get_time_in_ms();
	while (!table->monitor->philo_dead)
	{
		if (get_time_in_ms() - start >= time_in_ms)
			break ;
		usleep(500);
	}
} // still need to check