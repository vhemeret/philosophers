/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:25:02 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/13 02:46:01 by vahemere         ###   ########.fr       */
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

static int	check_philo_value(t_data *data)
{
	if (data->philo > 200 || data->philo == 0)
		return (0);
	else if (data->time_death < 60 || data->time_eat < 60 || data->time_sleep < 60)
		return (0);
	else if (data->time_death > INT_MAX || data->time_eat > INT_MAX
		|| data->time_sleep > INT_MAX)
		return (0);
	else if (data->nb_eating == 0 || data->nb_eating > INT_MAX)
		return (0);
	return (1);
}

int	check_error(t_data *data, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (!check_if_digits(av))
		return (0);
	data->philo = ft_atoi(av[1]);
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_eating = ft_atoi(av[5]);
	if (!check_philo_value(data))
		return (0);
	return (1);
}
