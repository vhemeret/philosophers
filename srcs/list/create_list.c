/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:46:10 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/12 18:42:06 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static t_phil	*add_node()
{
	t_phil	*new_elem;

	new_elem = malloc(sizeof(t_phil) * (1));
	if (!new_elem)
		return (NULL);
	new_elem->index++;
	return (new_elem);
}

int	create_list(t_core *core)
{
	t_phil	*first_node;
	t_phil	*tmp;
	int		i;

	i = -1;
	first_node = malloc(sizeof(t_phil) * (1));
	if (!first_node)
		return (0);
	first_node->index = 0;
	while (++i < core->data->philo)
	{
		if (i == 0)
		{
			tmp = add_node();
			first_node->next = tmp;
			if (core->data->philo == 1)
			{
				tmp->next = first_node;
				return (1);
			}
		}
		else if (i + 1 == core->data->philo)
		{
			tmp->next = add_node();
			tmp->next->next = first_node;
			return (1);
		}
		else if (i < core->data->philo)
			tmp->next = add_node();
	}
	printf("ne doit pas passer ici\n");
	return (0);
}
