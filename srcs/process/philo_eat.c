/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 00:07:42 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/17 07:04:03 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_print_eat(t_phil *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("\033[32m[%i]\033[35m philo%i has taken a fork\033[00m\n", get_time(philo->data->time_start), philo->index);
	printf("\033[32m[%i]\033[35m philo%i has taken a fork\033[00m\n", get_time(philo->data->time_start), philo->index);
	printf("\033[32m[%i]\033[33m philo%i is eating\033[00m\n", get_time(philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->print);
}

void	take_fork(t_phil *philo)
{
	if (!is_philo_dead(philo))
	{
		pthread_mutex_lock(&philo->next->fork);
		pthread_mutex_lock(&philo->fork);
		if (philo->next->nb_fork == 1)
		{
			philo->next->nb_fork = 0;
			philo->nb_fork = 2;
		}
	}
}

void	to_release_fork(t_phil *philo)
{
	if (/*!is_philo_dead(philo) && */philo->nb_fork == 2)
	{
		philo->next->nb_fork = 1;
		philo->nb_fork = 1;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

void	philo_eat(t_phil *philo)
{	
	take_fork(philo);
	if (!is_philo_dead(philo))
	{
		philo_print_eat(philo);
		usleep(philo->data->time_eat * 1000);
		pthread_mutex_lock(&philo->data->check_time);
		philo->time = get_time(0);
		pthread_mutex_unlock(&philo->data->check_time);
		to_release_fork(philo);
	}
}
