/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:23:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/13 19:13:18 by vahemere         ###   ########.fr       */
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

# define INT_MAX 2147483647

typedef struct	s_data
{
	int				philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				nb_eating;
	int				is_dead;
	pthread_mutex_t	launch;
	pthread_mutex_t	print;
	pthread_mutex_t	check_death;
}				t_data;

typedef struct	s_phil
{
	pthread_t		philo;
	int				index;
	int				nb_eat;
	int				forks;
	t_data			*data;
	struct s_phil	*next;
	suseconds_t		ms;
	time_t			sc;
	int				time;
	//pthread_mutex_t forks;
	pthread_mutex_t	mutex;
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
int		check_error(t_data *data, int ac, char **av);

/* STRUCT */
t_core	*malloc_struct();

/* LIST */
void		create_list(t_core *core, t_phil **lst);

/* PROCESS */
void	create_threads(t_core *core, t_phil *lst);

#endif
