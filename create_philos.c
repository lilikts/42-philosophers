#include "philo.h"

static int	create_philo(t_philo *philo, t_table *table, int count)
{
	memset(philo, 0, sizeof(*philo));
	philo->id = count;
	philo->table = table;
	philo->last_meal = table->start_time; // still needs to be set
	if (pthread_mutex_init(&philo->last_meal, NULL) != NULL)
		return (-1);
	if (philo->meals_eaten && pthread_mutex_init(&philo->meals_eaten, NULL) != NULL)
		return (-1);
	
}

t_philo	**create_philos(t_table *table)
{
    t_philo **philos;
	int		i;

	philos = malloc(sizeof(t_philo *) * table->philo_count);
	i = 0;
	if (!philos)
		return (NULL);
	while (i < table->philo_count)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			cleanup_philos(philos, i);
			return (NULL);
		}
		if (create_philo(philos[i], table, i) != 0)
		{
			free(philos[i]);
			cleanup_philos(philos, i);
			return (NULL);
		}
		i++;
	}
	return (philos);
}

// create philos
	// create array
	// while loop for each philo
		// mallc an extra philo
		// create philo
			// create mutexes 
			// set variables
		// create fork
			// speacial case last philo
			// create right
			// set left
		// error
			// destroy all philos/mutexes
		