/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:40:22 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/13 17:40:40 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_sleep(long time_in_ms, t_table *table)
{
	long	start;

	start = get_time_in_ms();
	while (!check_death_flag(table))
	{
		if (get_time_in_ms() - start >= time_in_ms)
			break ;
		usleep(500);
	}
}
