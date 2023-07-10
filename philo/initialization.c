/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:54:06 by smorphet          #+#    #+#             */
/*   Updated: 2023/06/21 10:37:22 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	initialize_arrays(t_prog *prog)
{
	int	count;

	count = 0;
	prog->philo_array = malloc(sizeof (t_philo) * prog->number_of_philos);
	if (!prog->philo_array)
		return (ERROR);
	while (count < prog->number_of_philos)
	{
		prog->philo_array[count] = malloc(sizeof(t_philo));
		if (!prog->philo_array[count])
		{
			printf("Failed to allocate memory for t_philo structure\n");
			break ;
		}
		count++;
	}
	prog->forks = malloc(sizeof (pthread_mutex_t) * prog->number_of_philos);
	if (!prog->forks)
		return (ERROR);
	return (0);
}

static int	initialize_mutex(t_prog *prog)
{
	int	count;

	count = 0;
	if (pthread_mutex_init(&prog->hordor, NULL) != 0)
		printf("\n Hordor mutex init has failed\n");
	if (pthread_mutex_init(&prog->death_mutex, NULL) != 0)
		printf("\n Death mutex init has failed\n");
	while (count < prog->number_of_philos)
	{
		if (pthread_mutex_init(&prog->forks[count], NULL) != 0)
		{
			printf("Failed to initialize mutex for fork %d\n", count);
			return (ERROR);
		}
		count++;
	}
	return (0);
}

int	initialize_struct(char **argv, t_prog *prog)
{
	prog->death_flag = 0;
	prog->start_time = 0;
	prog->number_of_philos = ph_atoi(argv[1]);
	if ((argv[1] && prog->number_of_philos == 0) || \
	prog->number_of_philos > 500)
	{
		printf("Number of philosophers must be more than 0\n");
		return (ERROR);
	}
	if (argv[2])
		prog->time_to_die = ph_atoi(argv[2]);
	if (argv[3])
		prog->time_to_eat = ph_atoi(argv[3]);
	if (argv[4])
		prog->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		prog->number_times_eat = ph_atoi(argv[5]);
	else
		prog->number_times_eat = -1;
	if (initialize_arrays(prog))
		return (ERROR);
	if (initialize_mutex(prog))
		return (ERROR);
	return (0);
}
