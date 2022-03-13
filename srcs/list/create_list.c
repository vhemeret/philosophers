/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:46:10 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/13 01:06:49 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

// static t_phil	*add_node()
// {
// 	t_phil	*new_elem;

// 	new_elem = malloc(sizeof(t_phil) * (1));
// 	if (!new_elem)
// 		return (NULL);
// 	return (new_elem);
// }

void	create_node(t_phil **lst, t_phil **tmp, t_core *core)
{
	int		i;

	i = -1;
	while (++i < core->data->philo)
	{
		(*tmp)->next = malloc(sizeof(t_phil) * (1));
		if (!(*tmp)->next)
			return ;
		(*tmp) = (*tmp)->next;
		(*tmp)->index += 1;
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
	(*lst)->index = 1;
	tmp = *lst;
	create_node(lst, &tmp, core);
}
