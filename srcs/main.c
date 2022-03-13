/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 03:51:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/13 00:56:24 by vahemere         ###   ########.fr       */
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

void	print_list(t_phil **lst)
{
	while (*lst)
	{
		printf("philo -> %i\n", (*lst)->index);
		(*lst) = (*lst)->next;
	}
}

int	main(int ac, char **av)
{
	t_core	*core;
	t_phil	*lst;

	lst = NULL;
	core = malloc_struct();
	if (!core)
		return (0);
	if (!check_error(core->data, ac, av))
	{
		printf("\033[35m Error into arguments.\n \033[00m");
		return (cleaning(core));
	}
	create_list(core, &lst);
	printf("list created\n");
	print_list(&lst);
	return (0);
}
