/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 16:53:44 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	need_space(t_philos *phis, int n_phis)
{
	int	i;

	i = 0;
	phis = malloc(sizeof(t_philos) * n_phis);
	if (!phis)
		errorminator(ERR_MEM);
	printf("[%p]\n", (void *)&phis);
	while(i < n_phis)
	{
		phis[i].in = malloc(sizeof(t_inputs));
		if (!phis[i].in)
			errorminator(ERR_MEM);
		printf("[%p]\n", (void *)&phis[i].in);
		i++;
	}
}
