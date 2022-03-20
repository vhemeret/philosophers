/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_stuct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:18:29 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/20 22:12:12 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	init_struct(t_data *data, int ac, char **av)
{
	data->philo = ft_atoi(av[1]);
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_eat = ft_atoi(av[5]);
	else
		data->nb_eat = -1;
	data->is_dead = 0;
	data->all_eat = 0;
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->check_death, NULL);
	pthread_mutex_init(&data->check_time, NULL);
	pthread_mutex_init(&data->eating, NULL);
	pthread_mutex_init(&data->full, NULL);
}

t_core	*malloc_and_init_struct(int ac, char **av)
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
	init_struct(core->data, ac, av);
	return (core);
}
