/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:13:47 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/06 12:27:46 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf
#include <unistd.h> // write, usleep
#include <string.h> // memset
#include <stdlib.h> // malloc, free
#include <sys/time.h> // gettimeofday
#include <pthread.h> // pthread_*

struct philo
{
	int		num;
	struct	philo* next;
};
typedef struct philo philo_t;

