/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:00:19 by lkloters          #+#    #+#             */
/*   Updated: 2025/07/30 14:20:27 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_thread()

void	start_simulation(t_data *data)
{ 
	int	i;

	data->start_time = get_time();
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create() != 0)
			handle_error("Failed to create thread!");
		i++;
	}
	// pthread _create for waiter
	// pthread_join
}