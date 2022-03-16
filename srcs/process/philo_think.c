/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:43:02 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/16 04:20:19 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_think(t_phil *philo)
{
	if (!is_philo_dead(philo))
	{
		pthread_mutex_lock(&philo->data->print);
		printf("\033[32m[%i]\033[34m philo%i is thinking\033[00m\n", get_time(philo->data->time_start), philo->index);
		pthread_mutex_unlock(&philo->data->print);
	}	
}
