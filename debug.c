/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:23:18 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/13 13:20:33 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	debug_table(t_table *table)
// {
// 	if (!table)
// 	{
// 		printf("table is NULL\n");
// 		return;
// 	}

// 	printf("=== TABLE DEBUG ===\n");
// 	printf("start_time: %ld\n", table->start_time);
// 	printf("philo_dead: %s\n", table->philo_dead ? "true" : "false");
// 	printf("all_full: %s\n", table->all_full ? "true" : "false");

// 	// Print data
// 	if (table->data)
// 	{
// 		printf("\n-- DATA --\n");
// 		printf("philo_count: %ld\n", table->data->philo_count);
// 		printf("time_to_die: %ld\n", table->data->time_to_die);
// 		printf("time_to_eat: %ld\n", table->data->time_to_eat);
// 		printf("time_to_sleep: %ld\n", table->data->time_to_sleep);
// 		printf("meals_to_eat: %ld\n", table->data->meals_to_eat);
// 	}
// 	else
// 		printf("\n-- DATA -- NULL\n");

// 	// Print status
// 	if (table->status)
// 	{
// 		printf("\n-- STATUS --\n");
// 		printf("fork_status: %ld\n", table->status->fork_status);
// 		printf("print_status: %ld\n", table->status->print_status);
// 		printf("meal_status: %ld\n", table->status->meal_status);
// 		printf("is_full_status: %ld\n", table->status->is_full_status);
// 		printf("death_log_status: %ld\n", table->status->death_log_status);
// 	}
// 	else
// 		printf("\n-- STATUS -- NULL\n");

// 	// Print philosophers
// 	if (table->philo)
// 	{
// 		printf("\n-- PHILOSOPHERS --\n");
// 		for (int i = 0; i < table->data->philo_count; i++)
// 		{
// 			t_philo *p = &table->philo[i];
// 			printf("Philo %d:\n", p->id);
// 			printf("  meals_eaten: %d\n", p->meals_eaten);
// 			printf("  last_meal: %ld\n", p->last_meal);
// 			printf("  data ptr: %p\n", (void*)p->data);
// 			printf("  status ptr: %p\n", (void*)p->status);
// 			printf("  table ptr: %p\n", (void*)p->table);
// 		}
// 	}
// 	else
// 		printf("\n-- PHILOSOPHERS -- NULL\n");

// 	printf("====================\n");
// }