/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:14:48 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/07 14:15:00 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(void *arg)
{
    (void)arg; // unused parameter
    // Simuliere Philosophenarbeit
    sleep(1);
    return NULL;
}

void *monitor_routine(void *arg)
{
    (void)arg; // unused parameter
    // Simuliere Monitoring
    sleep(1);
    return NULL;
}