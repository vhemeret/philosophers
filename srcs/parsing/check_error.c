/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:25:02 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/14 22:41:44 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static int	check_if_digits(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		if (j > 9 || av[i][j] > '7')
			return (0);
	}
	return (1);
}

static int	check_philo_value(int ac, char **av)
{
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) == 0)
		return (0);
	else if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (0);
	else if (ft_atoi(av[2]) > INT_MAX || ft_atoi(av[3]) > INT_MAX
		|| ft_atoi(av[4]) > INT_MAX)
			return (0);
	if (ac == 6)
		if (ft_atoi(av[5]) == 0 || ft_atoi(av[5]) > INT_MAX)
			return (0);
	return (1);
}

int	check_error(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (!check_if_digits(av))
		return (0);
	if (!check_philo_value(ac, av))
		return (0);
	return (1);
}
