/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:09:31 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/15 05:32:35 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_sleep(t_phil *philo)
{
	
	if (!is_philo_dead(philo))
	{
		printf("[%i] philo%i is sleeping\n", get_time(philo->data->time), philo->index);
		usleep(philo->data->time_death);
	}
}

void	take_forks(t_phil *philo)
{
	
}

void	philo_eat(t_phil *philo)
{
	if (!is_philo_dead(philo))
	{
		
	}
}
// void	philo_sleep(t_phil *philo)
// {
// 	if (is_philo_dead() == FALSE)
// 	{
// 		get_time();
// 		printf(...);
// 		my_usleep();
// 	}
// }

// thinking
// get_time();
// printf(...);