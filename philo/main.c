/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:59:20 by smorphet          #+#    #+#             */
/*   Updated: 2023/07/10 15:35:45 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo(t_prog *prog, int i)
{
	prog->philo_array[i]->fork_l = i;
	prog->philo_array[i]->fork_r = (i + 1) % \
	prog->number_of_philos;
	prog->philo_array[i]->philo_index = i;
	prog->philo_array[i]->prog_info = prog;
	prog->philo_array[i]->eaten_count = 0;
}

void	make_threads(t_prog *prog)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&prog->hordor);
	while (i < prog->number_of_philos)
	{
		if (pthread_mutex_init(&prog->philo_array[i]->eaten_mutex, NULL) != 0)
			printf("\n Eat mutex init has failed\n");
		init_philo(prog, i);
		if (pthread_create(&prog->philo_array[i]->thread, NULL, \
		(void *) philo_routine, (void *) prog->philo_array[i]) != 0)
		{
			printf("Failed to create the thread\n");
			prog->death_flag = 1;
			pthread_mutex_unlock(&prog->hordor);
			return ;
		}
		i++;
	}
	prog->start_time = get_time();
	pthread_mutex_unlock(&prog->hordor);
	monitoring(prog);
}

void	clean_up(t_prog *prog)
{
	int	count;

	count = 0;
	if (prog->philo_array)
	{
		while (count < prog->number_of_philos)
		{
			pthread_mutex_destroy(&prog->philo_array[count]->eaten_mutex);
			if (prog->philo_array[count])
				free(prog->philo_array[count]);
			count++;
		}
		if (prog->philo_array)
			free(prog->philo_array);
	}
	pthread_mutex_destroy(&prog->hordor);
	pthread_mutex_destroy(&prog->death_mutex);
	while (count < prog->number_of_philos)
	{
		pthread_mutex_destroy(&prog->forks[count]);
		count++;
	}
	if (prog->forks)
		free(prog->forks);
}

int	main(int argc, char **argv)
{
	t_prog	prog;

	if (argc != 5 && argc != 6)
	{
		printf("Incorrect number of arguments: ");
		printf("number_of_philos, time_to_die, time_to_eat, time_to_sleep. ");
		printf("Optional: number_of_times_each_philosopher_must_eat\n");
		return (0);
	}
	if (process_argv(argv, argc) == ERROR)
		return (0);
	if (initialize_struct(argv, &prog) == ERROR)
	{
		clean_up(&prog);
		return (0);
	}
	make_threads(&prog);
	ft_pthread_exit(&prog);
	pthread_join(prog.monitoring_thread, NULL);
	clean_up(&prog);
	return (0);
}
