/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:51 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/18 14:47:53 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	destroy_mutex_data(t_data *data)
{
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->check_death);
	pthread_mutex_destroy(&data->check_time);
	pthread_mutex_destroy(&data->eating);
}

static void cleaning_list(t_phil *philo)
{
	int		i;
	int		nb_philo;
	t_phil	*tmp;

	i = -1;
	nb_philo = philo->data->philo;
	while (++i < nb_philo)
	{
		pthread_mutex_destroy(&philo->mutex);
		pthread_mutex_destroy(philo->fork);
		tmp = philo;
		philo = philo->next;
		free(tmp);
		tmp = NULL;
	}
}

static void	cleaning_struct(t_core *core)
{
	free(core->data);
	free(core);
}

int	cleaning(t_core *core)
{
	destroy_mutex_data(core->data);
	cleaning_list(core->philo);
	cleaning_struct(core);
	return (0);
}
