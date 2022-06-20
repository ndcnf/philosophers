/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:26:09 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/20 17:29:56 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_usec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("[%ld] seconds\n[%d] micro seconds\n", time.tv_sec, time.tv_usec);
	printf("[%d] usec entre le message avant et celui ci", time.tv_usec);
}
