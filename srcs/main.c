/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:51:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/15 01:50:29 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int	i;
// pthread_mutex_t	mutex;
// 
// void	*test_routine()
// {
	// int j;
// 
	// j = 0;
	// while (j++ < 1000000)
	// {
		// pthread_mutex_lock(&mutex);
		// i++;
		// pthread_mutex_unlock(&mutex);
	// }
// }
// 
// int	main(int ac, char **av)
// {
	// t_struct *data;
	// 
	// if (!check_error(data, ac, av))
		// return (0);
// 
	// pthread_t	philo1;
	// pthread_t	philo2;
	// pthread_t	philo3;
// 
	// pthread_mutex_init(&mutex, NULL);
	// if (pthread_create(&philo1, NULL, &test_routine, NULL) != 0)
		// printf("\033[35m	Thread 1 fail\n \033[00m");
	// if (pthread_create(&philo2, NULL, &test_routine, NULL) != 0)
		// printf("\033[36m	Thread 2 fail\n \033[00m");
	// if (pthread_create(&philo3, NULL, &test_routine, NULL) != 0)
		// printf("\033[34m	Thread 3 fail\n \033[00m");
	// pthread_join(philo1, NULL);
	// pthread_join(philo2, NULL);
	// pthread_join(philo3, NULL);
	// pthread_mutex_destroy(&mutex);
	// printf("%i\n", i);
	// 
	// return (0);
// }

void	print_list(t_phil **lst, t_core *core)
{
	int i;

	i = -1;
	printf("\033[32mList created\033[00m\n");
	while (++i < core->data->philo)
	{
		printf("\033[35mphilo -> %i\033[00m\n", (*lst)->index);
		printf("\033[36mnb meals -> %i\033[00m\n", (*lst)->nb_eat);
		printf("\033[34mnb fork(s) -> %i\033[00m\n\n", (*lst)->forks);
		(*lst) = (*lst)->next;
	}
}


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
	//print_list(&lst, core);
	create_threads(core, lst);
	return (0);
}
