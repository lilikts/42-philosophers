/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:06:56 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/06 21:11:05 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void print_data(const t_data *data)
{
	if (!data)
	{
		printf("data is NULL\n");
		return;
	}
	printf("=== t_data ===\n");
	printf("philo_count   : %ld\n", data->philo_count);
	printf("time_to_die   : %ld\n", data->time_to_die);
	printf("time_to_eat   : %ld\n", data->time_to_eat);
	printf("time_to_sleep : %ld\n", data->time_to_sleep);
	printf("meals_to_eat  : %ld\n", data->meals_to_eat);
	printf("\n");
}

static void print_philos(const t_philo *philos, long count)
{
	if (!philos)
	{
		printf("philos is NULL\n");
		return;
	}
	printf("=== t_philo (array of %ld philosophers) ===\n", count);
	for (long i = 0; i < count; i++)
	{
		printf("Philo #%d:\n", philos[i].id);
		printf("  Meals eaten : %d\n", philos[i].meals_eaten);
		printf("  Last meal   : %ld\n", philos[i].last_meal);
		printf("  Is dead     : %s\n", philos[i].is_dead ? "true" : "false");
		printf("  Left fork   : %p\n", (void *)philos[i].left_fork);
		printf("  Right fork  : %p\n", (void *)philos[i].right_fork);
	}
	printf("\n");
}

void print_table(const t_table *table)
{
	if (!table)
	{
		printf("table is NULL\n");
		return;
	}
	printf("=== t_table ===\n");
	printf("Start time    : %ld\n", table->start_time);
	printf("Forks         : %p\n", (void *)table->forks);
	printf("Print mutex   : %p\n", (void *)&table->print_mutex);
	printf("Death mutex   : %p\n", (void *)&table->death_mutex);
	printf("\n");

	print_data(table->data);
	print_philos(table->philo, table->data ? table->data->philo_count : 0);
}