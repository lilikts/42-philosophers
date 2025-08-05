/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:22:05 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/05 19:48:53 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_error(const char *msg, void *data, void *table, void *philo)
{
	if (msg)
		printf(stderr, "Error: %s!\n", msg);
	if (philo)
		free(philo);
	if (table)
		free(table);
	if (data)
		free(data);
}

void	cleanup_philos(t_philo **philos, int count)
{
	int	i;

	i = 0;
	if (!philos)
		return ;
	while (i < count)
	{
		destroy_mutexes(philos[i]);
		free(philos[i]);
		i++;
	}
	free(philos);
}