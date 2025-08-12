/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:51:45 by lkloters          #+#    #+#             */
/*   Updated: 2025/08/12 12:31:07 by lkloters         ###   ########.fr       */
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

typedef struct s_data
{
	long	philo_count;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_to_eat;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	bool			is_dead;
	pthread_t		philo_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
	struct s_data	*data;
}	t_philo;

typedef struct s_monitor
{
	pthread_t	monitor_thread;
	bool		philo_dead;
	long		philo_full;
}	t_monitor;

typedef struct s_status
{
	long	fork_status;
	long	print_status;
	long	meal_status;
	long	death_log_status;
}	t_status;

typedef struct s_table
{
	t_data			*data;
	t_philo			*philo;
	t_monitor		*monitor;
	t_status		*status;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	long			start_time;
	long			philo_count;
}	t_table;

// parsing
t_data	*parse_input(int argc, char **argv);

// initialize
t_table	*init_structs(t_data *data);
void	start_simulation(t_data *data, t_table *table);
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);

// utils
long	safe_atol(char *str);
long	get_time_in_ms(void);
int		create_forks(t_data *data, t_table *table);
void	print_action(t_philo *philo, const char *action);
long	timestamp(t_table *table);
void	smart_sleep(long time_in_ms, t_table *table);

// validate input
bool	valid_arguments(int argc, char **argv);
bool	valid_input(t_data *data, int argc);

// routine
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	rest(t_philo *philo);
void	release_forks(t_philo *philo);
void	think(t_philo *philo);

// cleanup
void	cleanup(t_data *data, t_table *table);
void	handle_error(const char *msg, t_data *data, t_table *table);

#endif