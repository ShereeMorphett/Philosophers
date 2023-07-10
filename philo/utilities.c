/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:58:28 by smorphet          #+#    #+#             */
/*   Updated: 2023/07/10 12:09:02 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	non_usleep(int ms, t_prog *prog)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
	{
		pthread_mutex_lock(&prog->death_mutex);
		if (prog->death_flag == 1)
		{
			pthread_mutex_unlock(&prog->death_mutex);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&prog->death_mutex);
			usleep(500);
		}
	}
}

int	ft_pthread_exit(t_prog *prog)
{
	int	count;

	count = prog->number_of_philos - 1;
	while (count >= 0)
	{
		pthread_join(prog->philo_array[count]->thread, NULL);
		count--;
	}
	return (SUCCESS);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned long)1000) + tv.tv_usec / 1000);
}

void	printer(t_philo *philo, char *print)
{
	long long int	time;

	time = get_time() - philo->prog_info->start_time;
	pthread_mutex_lock(&philo->prog_info->death_mutex);
	if (philo->prog_info->death_flag == 0)
		printf("%lld %d %s", time, philo->philo_index + 1, print);
	pthread_mutex_unlock(&philo->prog_info->death_mutex);
}
