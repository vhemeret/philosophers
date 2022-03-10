/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:23:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/11 00:37:02 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define INT_MAX 2147483647

typedef struct s_data
{
	int	philo;
	int	time_death;
	int	time_eat;
	int	time_sleep;
	int	nb_eating;
}				t_data;

typedef struct s_phil
{
	
}				t_phil;


/*####################### MANDATORY PART #######################*/

/* PARSING */
int		check_error(t_data *data, int ac, char **av);

/* UTILS */
int		ft_atoi(const char *nptr);

#endif