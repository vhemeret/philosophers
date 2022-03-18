/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:56:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/18 14:42:17 by vahemere         ###   ########.fr       */
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

void	*check_death(void *lst)
{
	t_phil	*philo;

	philo = (t_phil *)lst;
	while (!is_philo_dead(philo))
	{
		pthread_mutex_lock(&philo->data->check_time);
		if (get_time(philo->time) >= philo->data->time_death && !is_philo_dead(philo))
		{
			pthread_mutex_lock(&philo->data->check_death);
			philo->data->is_dead = 1;
			pthread_mutex_unlock(&philo->data->check_death);
			pthread_mutex_lock(&philo->data->print);
			printf("\033[32m[%i]\033[31m philo%i died\033[00m\n", get_time(philo->data->time_start), philo->index);
			pthread_mutex_unlock(&philo->data->print);
		}
		pthread_mutex_unlock(&philo->data->check_time);
	}
	return (lst);
}

void	*routine(void *node)
{
	t_phil	*philo;

	philo = (t_phil *)node;
	if (philo->index % 2 == 0)
		usleep(100);
	while (!is_philo_dead(philo) && !check_meal(philo))
	{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
	}
	return (node);
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

void	manage_philo(t_core *core, t_phil *lst)
{
	int		i;
	t_phil	*tmp;

	i = -1;
	tmp = lst;
	core->data->time_start = get_time(0);
	while (++i < core->data->philo)
	{
		tmp->time = get_time(0);
		pthread_create(&(tmp->philo), NULL, routine, tmp);
		pthread_create(&(tmp->death), NULL, check_death, tmp);
		tmp = tmp->next;
	}
	join_threads(lst, core);
}
