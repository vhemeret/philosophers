/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:09:31 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/17 00:01:22 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_sleep(t_phil *philo)
{
	if (!is_philo_dead(philo))
	{
		pthread_mutex_lock(&philo->data->print);
		printf("\033[32m[%i]\033[36m philo%i is sleeping\033[00m\n", get_time(philo->data->time_start), philo->index);
		pthread_mutex_unlock(&philo->data->print);
		usleep(philo->data->time_sleep * 1000);
	}
}
