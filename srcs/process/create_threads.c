/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:56:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/13 19:03:51 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*test_routine()
{
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
	//pthread_mutex_init(lst->forks, NULL);
	while (++i < core->data->philo)
	{
		pthread_create(&tmp->philo, NULL, &test_routine, NULL);
		printf("%i\n", tmp->index);
		tmp = tmp->next;
	}
	join_threads(lst, core);
	//core->philo->ms = gettimeofday(NULL, NULL);
	printf("philo thread(s) created\n");
}
