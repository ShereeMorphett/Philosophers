/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:18:58 by smorphet          #+#    #+#             */
/*   Updated: 2023/07/10 13:46:18 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	are_they_full(t_prog *prog)
{
	int	full;
	int	count;

	full = 0;
	count = 0;
	while (count < prog->number_of_philos)
	{
		pthread_mutex_lock(&prog->philo_array[count]->eaten_mutex);
		if (prog->philo_array[count]->eaten_count >= prog->number_times_eat)
		{
			full++;
			if (full >= prog->number_of_philos)
			{
				pthread_mutex_unlock(&prog->philo_array[count]->eaten_mutex);
				pthread_mutex_lock(&prog->death_mutex);
				prog->death_flag = 1;
				pthread_mutex_unlock(&prog->death_mutex);
				ft_pthread_exit(prog);
			}
		}
		pthread_mutex_unlock(&prog->philo_array[count]->eaten_mutex);
		count++;
	}
}

static int	check_death(t_prog *prog, int counter)
{
	pthread_mutex_lock(&prog->philo_array[counter]->eaten_mutex);
	if ((get_time() - prog->philo_array[counter]->time_last_ate) > \
		(long)prog->time_to_die)
	{
		pthread_mutex_unlock(&prog->philo_array[counter]->eaten_mutex);
		printer(prog->philo_array[counter], "has died\n");
		pthread_mutex_lock(&prog->death_mutex);
		prog->death_flag = 1;
		pthread_mutex_unlock(&prog->death_mutex);
		pthread_mutex_unlock(&prog->forks[prog->philo_array[counter]->fork_l]);
		pthread_mutex_unlock(&prog->forks[prog->philo_array[counter]->fork_r]);
		ft_pthread_exit(prog);
		return (0);
	}
	pthread_mutex_unlock(&prog->philo_array[counter]->eaten_mutex);
	return (1);
}

void	monitoring(t_prog *prog)
{
	int	counter;
	int	full;

	full = 0;
	non_usleep(0.7 * prog->time_to_die, prog);
	while (1)
	{
		counter = 0;
		if (prog->number_times_eat > 0)
			are_they_full(prog);
		while (counter != prog->number_of_philos)
		{
			if (!check_death(prog, counter))
				return ;
			counter++;
		}
	}
	return ;
}
