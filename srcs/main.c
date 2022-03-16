/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:51:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/16 00:15:53 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_core	*core;
	t_phil	*lst;

	lst = NULL;
	if (!check_error(ac, av))
		printf("\033[35m Error into arguments.\033[00m\n");
	core = malloc_and_init_struct(ac, av);
	if (!core)
		return (0);
	create_list(core, &lst);
	core->philo = lst;
	create_threads(core, lst);
	return (0);
}
