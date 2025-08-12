/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:23:18 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 10:33:41 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void print_data(const t_data *data)
// {
//     printf("=== t_data ===\n");
//     printf("philo_count    : %ld\n", data->philo_count);
//     printf("time_to_die    : %ld\n", data->time_to_die);
//     printf("time_to_eat    : %ld\n", data->time_to_eat);
//     printf("time_to_sleep  : %ld\n", data->time_to_sleep);
//     printf("meals_to_eat   : %ld\n", data->meals_to_eat);
// }

// static void print_philos(const t_philo *philo, long count)
// {
//     printf("=== t_philo array (%ld philosophers) ===\n", count);
//     for (long i = 0; i < count; i++)
//     {
//         printf("-- Philosopher %d --\n", philo[i].id);
//         printf("meals_eaten : %d\n", philo[i].meals_eaten);
//         printf("last_meal   : %ld\n", philo[i].last_meal);
//         printf("is_dead     : %s\n", philo[i].is_dead ? "true" : "false");
//         printf("left_fork   : %p\n", (void *)philo[i].left_fork);
//         printf("right_fork  : %p\n", (void *)philo[i].right_fork);
//     }
// }

// static void print_monitor(const t_monitor *monitor)
// {
//     printf("=== t_monitor ===\n");
//     printf("philo_dead : %s\n", monitor->philo_dead ? "true" : "false");
//     printf("philo_full : %ld\n", monitor->philo_full);
// }

// static void print_status(const t_status *status)
// {
//     printf("=== t_status ===\n");
//     printf("fork_status      : %ld\n", status->fork_status);
//     printf("print_status     : %ld\n", status->print_status);
//     printf("meal_status      : %ld\n", status->meal_status);
//     printf("death_log_status : %ld\n", status->death_log_status);
// }

// void print_table_state(const t_table *table)
// {
//     if (!table)
//     {
//         printf("Table pointer is NULL\n");
//         return;
//     }

//     printf("\n==== TABLE STATE ====\n");
//     printf("start_time  : %ld\n", table->start_time);
//     printf("philo_count : %ld\n\n", table->philo_count);

//     if (table->data)     print_data(table->data);
//     if (table->philo)    print_philos(table->philo, table->philo_count);
//     if (table->monitor)  print_monitor(table->monitor);
//     if (table->status)   print_status(table->status);

//     printf("=====================\n");
// }
