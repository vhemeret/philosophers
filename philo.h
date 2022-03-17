/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:23:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/17 06:36:36 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
#define ICI printf("ICI\n");

# define INT_MAX	2147483647

typedef struct	s_data
{
	int				philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				nb_eating;
	int				is_dead;
	int				time_start;
	pthread_mutex_t	print;
	pthread_mutex_t	check_death;
	pthread_mutex_t	check_time;
}				t_data;

typedef struct	s_phil
{
	pthread_t		death;
	pthread_t		philo;
	int				index;
	int				nb_eat;
	int				nb_fork;
	int				time;
	t_data			*data;
	struct s_phil	*next;
	pthread_mutex_t	mutex;
	pthread_mutex_t fork;
}				t_phil;

typedef struct	s_core
{
	t_data	*data;
	t_phil	*philo;
}				t_core;

/*####################### MANDATORY PART #######################*/

/* CLEANING */
int		cleaning(t_core *core);

/* UTILS */
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

/* PARSING */
int		check_error(int ac, char **av);

/* STRUCT */
t_core	*malloc_and_init_struct(int ac, char **av);

/* LIST */
void	create_list(t_core *core, t_phil **lst);

/* PROCESS */
int		get_time(long time);
void	create_threads(t_core *core, t_phil *lst);
void	philo_eat(t_phil *philo);
void	philo_sleep(t_phil *phil);
void	philo_think(t_phil *philo);
int		is_philo_dead(t_phil *philo);

#endif
