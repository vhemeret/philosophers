/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:46:10 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/18 16:28:45 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	init_philo(t_phil **philo, t_core *core)
{
	static int	index;

	index += 1;
	(*philo)->fork = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*philo)->fork, NULL);
	pthread_mutex_init(&(*philo)->mutex, NULL);
	(*philo)->index = index;
	(*philo)->nb_eat = 0;
	(*philo)->nb_fork = 1;
	(*philo)->data = core->data;
}

static void	create_node(t_phil **lst, t_phil **tmp, t_core *core)
{
	int		i;

	i = 0;
	while (++i < core->data->philo)
	{
		(*tmp)->next = malloc(sizeof(t_phil) * (1));
		if (!(*tmp)->next)
			return ;
		(*tmp) = (*tmp)->next;
		init_philo(tmp, core);
	}
	(*tmp)->next = (*lst);
}

void	create_list(t_core *core, t_phil **lst)
{
	t_phil	*tmp;

	(*lst) = malloc(sizeof(t_phil) * (1));
	if (!lst)
		return ;
	if (core->data->philo == 1)
		(*lst)->next = *lst;
	init_philo(lst, core);
	tmp = *lst;
	create_node(lst, &tmp, core);
}
