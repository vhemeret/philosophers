/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:51:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/20 17:35:00 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_core	*core;
	t_phil	*lst;

	lst = NULL;
	if (!check_error(ac, av))
	{
		printf("\033[35m Error into arguments.\033[00m\n");
		return (0);
	}
	core = malloc_and_init_struct(ac, av);
	if (!core)
		return (0);
	create_list(core, &lst);
	core->philo = lst;
	if (core->data->philo == 1)
		manage_one_philo(core, lst);
	else
		manage_philo(core, lst);
	cleaning(core);
	return (0);
}
