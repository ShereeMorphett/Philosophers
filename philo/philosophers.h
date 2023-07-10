/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorphet <smorphet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:37:55 by smorphet          #+#    #+#             */
/*   Updated: 2023/07/10 13:26:42 by smorphet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h> 
# include <unistd.h>
# include <sys/time.h>

# define ERROR 1
# define SUCCESS 0

typedef struct s_prog	t_prog;

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_index;
	long long		time_last_ate;
	t_prog			*prog_info;
	int				fork_l;
	int				fork_r;
	int				eaten_count;
	pthread_mutex_t	eaten_mutex;

}	t_philo;

typedef struct s_prog
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_times_eat;
	t_philo			**philo_array;
	long long		start_time;
	int				death_flag;
	int				times_eaten;
	pthread_t		monitoring_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	hordor;

}	t_prog;

int			initialize_struct(char **argv, t_prog *prog);
void		printer(t_philo *philo, char *print);
long long	get_time(void);
void		non_usleep(int ms, t_prog *prog);
int			process_argv(char *argv[], int argc);
int			ph_atoi(const char *str);
int			philo_routine(void *philo_data);
void		monitoring(t_prog *prog_data);
int			ft_pthread_exit(t_prog *prog);

#endif