/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_one_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:35:28 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/20 17:52:11 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*routine_one_philo(void *lst)
{
	t_phil	*tmp;

	tmp = (t_phil *)lst;
	tmp->time = get_time(0);
	pthread_mutex_lock(&tmp->data->print);
	printf("\033[32m[%i]\033[35m philo%i has taken a fork\033[00m\n", get_time(tmp->data->time_start), tmp->index);
	pthread_mutex_unlock(&tmp->data->print);
	ft_usleep(tmp->data->time_death);
	pthread_mutex_lock(&tmp->data->print);
	printf("\033[32m[%i]\033[31m philo%i died\033[00m\n", get_time(tmp->data->time_start), tmp->index);
	pthread_mutex_unlock(&tmp->data->print);
	return (lst);
}

void	manage_one_philo(t_core *core, t_phil *lst)
{
	core->data->time_start = get_time(0);
	pthread_create(&lst->philo, NULL, routine_one_philo, lst);
	pthread_join(lst->philo, NULL);
}