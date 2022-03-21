/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:07:42 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/21 03:22:07 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	take_fork(t_phil *philo)
{
	if (!is_philo_dead(philo))
	{
		pthread_mutex_lock(philo->next->fork);
		if (philo->next->nb_fork == 1)
		{
			philo->next->nb_fork = 0;
			pthread_mutex_lock(philo->fork);
			philo->nb_fork = 2;
			return (2);
		}
	}
	return (0);
}

int	check_meal(t_phil *philo)
{
	if (!is_philo_dead(philo))
	{
		pthread_mutex_lock(&philo->data->eating);
		if (philo->data->nb_eat != -1)
		{
			if (philo->data->nb_eat == philo->nb_eat)
			{
				pthread_mutex_unlock(&philo->data->eating);
				return (1);
			}
		}
		else
		{
			pthread_mutex_unlock(&philo->data->eating);
			return (0);
		}
		pthread_mutex_unlock(&philo->data->eating);
	}
	return (0);
}

void	increment_meal(t_phil *philo)
{
	pthread_mutex_lock(&philo->data->eating);
	if (philo->data->nb_eat != -1)
	{
		if (philo->nb_eat < philo->data->nb_eat)
			philo->nb_eat++;
	}
	pthread_mutex_unlock(&philo->data->eating);
}

void	to_release_fork(t_phil *philo)
{
	if (philo->nb_fork == 2)
	{
		philo->nb_fork = 1;
		philo->next->nb_fork = 1;
		pthread_mutex_unlock(philo->next->fork);
		pthread_mutex_unlock(philo->fork);
	}
}

void	philo_eat(t_phil *philo)
{	
	if (!is_philo_dead(philo) && take_fork(philo) == 2)
	{
		if (!is_philo_dead(philo))
		{
			pthread_mutex_lock(&philo->data->print);
			printf("\033[32m[%i]\033[35m philo%i has taken a fork\033[00m\n",
				get_time(philo->data->time_start), philo->index);
			printf("\033[32m[%i]\033[35m philo%i has taken a fork\033[00m\n",
				get_time(philo->data->time_start), philo->index);
			printf("\033[32m[%i]\033[33m philo%i is eating\033[00m\n",
				get_time(philo->data->time_start), philo->index);
			pthread_mutex_unlock(&philo->data->print);
		}
		pthread_mutex_lock(&philo->data->check_time);
		philo->time = get_time(0);
		pthread_mutex_unlock(&philo->data->check_time);
		ft_usleep(philo->data->time_eat);
		increment_meal(philo);
		to_release_fork(philo);
	}
}
