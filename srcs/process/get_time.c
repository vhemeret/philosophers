/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:13:32 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/14 04:58:51 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	get_time(void)
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
	return (res);
}