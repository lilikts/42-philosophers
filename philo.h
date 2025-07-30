/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:51:45 by lkloters          #+#    #+#             */
/*   Updated: 2025/07/30 13:27:23 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eating_count;
	long	start_time;
}	t_data;

typedef struct s_philo
{
	int		id;
	int		eat_count;
	long	last_meal;
	t_data	*data;
}	t_philo;

typedef struct s_waiter
{
	t_data	*data;
}	t_waiter;


void parse_input(int argc, char **argv, t_data *data);

// init
void data_init(t_data *data);

// utils
long	safe_atol(char *str);
void	handle_error(char *msg);

// validate input
bool	valid_arguments(int argc, char **argv);
bool	valid_values(t_data *data);



#endif