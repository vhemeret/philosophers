/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:24:51 by vahemere          #+#    #+#             */
/*   Updated: 2022/03/12 18:34:00 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	clean_struct_success(t_core *core)
{
	free(core->data);
	free(core->philo);
	free(core);
}

int	cleaning(t_core *core)
{
	clean_struct_success(core);
	return (0);
}
