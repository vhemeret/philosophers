/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:56:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/15 05:30:22 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	is_philo_dead(t_phil *philo)
{
	pthread_mutex_lock(&philo->data->check_death);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->check_death);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->data->check_death);
	return (0);
}

void	*routine(void *node)
{
	t_phil	*philo;

	philo = (t_phil *)node;
	while (!is_philo_dead(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		// philo_think(philo);
	}
	return (NULL);
}

void	join_threads(t_phil *lst, t_core *core)
{
	int		i;
	t_phil	*tmp;

	i = -1;
	tmp = lst;
	while (++i < core->data->philo)
	{
		pthread_join(tmp->philo, NULL);
		tmp = tmp->next;
	}
}

void	create_threads(t_core *core, t_phil *lst)
{
	int		i;
	t_phil	*tmp;

	i = -1;
	tmp = lst;

	core->data->time = get_time(0);
	while (++i < core->data->philo)
	{
		pthread_create(&(tmp->philo), NULL, routine, (void *)tmp);
		tmp = tmp->next;
	}
	join_threads(lst, core);
}
