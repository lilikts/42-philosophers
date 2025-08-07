/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:51:45 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/07 10:45:44 by lkloters         ###   ########.fr       */
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
# include <string.h>
# include <sys/time.h>

typedef struct	s_data
{
	long	philo_count;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_to_eat;
}	t_data;

typedef struct s_philo
{
	int		id;
	int		meals_eaten;
	long	last_meal;
	bool			is_dead;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_table
{
	t_data			*data;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	long			start_time;
}	t_table;

t_table *handle_input(int argc, char **argv);

// utils
long	safe_atol(char *str);
long	get_time_in_ms(void);

// validate input
bool	valid_arguments(int argc, char **argv);
bool	valid_values(t_data *data);

// cleanup
void	cleanup(t_data *data, t_table *table, t_philo *philo);
void	handle_error(const char *msg, void *data, void *table, void *philo);

//print
void print_table(const t_table *table);

#endif