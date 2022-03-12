/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_stuct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:18:29 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/12 18:32:27 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_core	*malloc_struct()
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	if (!core)
		return (NULL);
	core->data = malloc(sizeof(t_data));
	if (!core->data)
	{
		free(core);
		return (NULL);
	}
	core->philo = malloc(sizeof(t_phil));
	if (!core->philo)
	{
		free(core->data);
		free(core);
		return (NULL);
	}
	return (core);
}
