/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:56:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/14 05:45:35 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*routine(void *lst)
{
	t_core	*core;

	core = (t_core *)lst;
	//while (core->data->is_dead == 0)
	//{
	//	check_philo_death(lst);
	//	philo_eat(lst);
	//	philo_sleep(lst);
	//	philo_think(lst);
	//	lst = lst->next;
	//}
	printf("je suis le philo -> %i\n", core->philo->index);
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
	core->philo->time = get_time();
	printf("%i\n", core->philo->time);
	while (++i < core->data->philo)
	{
		pthread_create(&tmp->philo, NULL, &routine, tmp);
		tmp = tmp->next;
	}
	join_threads(lst, core);
}
