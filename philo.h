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

typedef struct s_table
{
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals_to_eat;
	long	start_time;
	int		is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_philo	*philo;
}	t_table;

typedef struct s_philo
{
	int		id;
	int		meals_eaten;
	long	last_meal;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
	struct s_philo	*next;
}	t_philo;

void parse_input(int argc, char **argv, t_table *table);

// init
void table_init(t_table *table);

// utils
long	safe_atol(char *str);
void	handle_error(char *msg);

// validate input
bool	valid_arguments(int argc, char **argv);
bool	valid_values(t_table *table);



#endif