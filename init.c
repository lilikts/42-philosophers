/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:51:42 by lkloters          #+#    #+#             */
/*   Updated: 2025/07/22 17:00:57 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void table_init(t_table *table)
{
	if (!table)
		return;
	table->philo_count = 0;
	table->time_to_die = 0;
	table->time_to_eat = 0;
	table->time_to_sleep = 0;
	table->meals_to_eat = 0;
}