/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:13:47 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/06 15:20:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf
#include <unistd.h> // write, usleep
#include <string.h> // memset
#include <stdlib.h> // malloc, free
#include <sys/time.h> // gettimeofday
#include <pthread.h> // pthread_*

typedef struct s_philo
{
	int		id;
	struct	philo* next;
} t_philo;
