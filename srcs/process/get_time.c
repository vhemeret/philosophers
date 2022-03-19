/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:13:32 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/19 14:24:43 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	get_time(long time)
{
	struct timeval	current_time;
	int				res;

	res = 0;
	if (gettimeofday(&current_time, NULL) == -1)
	{
		printf("gettimeofday failed.\n");
		return (-1);
	}
	res = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (res - time);
}

void	ft_usleep(long ms)
{
	long int	start_time;
	long int	current_time;

	start_time = get_time(0);
	current_time = get_time(0);
	while ((current_time - start_time) <= ms)
	{
		current_time = get_time(0);
		usleep(100);
	}
}