/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:46:10 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/13 13:59:51 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	init_philo(t_phil **philo)
{
	static int	index;

	index += 1;
	(*philo)->index = index;
	(*philo)->nb_eat = 0;
	(*philo)->forks = 0;
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
		init_philo(tmp);
	}
	(*tmp)->next = (*lst);
}

void	create_list(t_core *core, t_phil **lst)
{
	int		i;
	t_phil	*tmp;

	i = -1;
	(*lst) = malloc(sizeof(t_phil) * (1));
	if (!lst)
		return ;
	if (core->data->philo == 1)
		(*lst)->next = *lst;
	init_philo(lst);
	tmp = *lst;
	create_node(lst, &tmp, core);
}
