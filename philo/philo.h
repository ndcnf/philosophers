/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:13:47 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/07 13:59:39 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf
# include <unistd.h> // write, usleep
# include <string.h> // memset
# include <stdlib.h> // malloc, free
# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread_*

// defines a philospher
// every philosopher is linked
//////////////////////////////
/* typedef struct s_philo
{
	int		id;
	t_spork	frk;
	struct	s_philo *next;
	struct	s_philo *prev;
} t_philo; */

typedef struct node
{
	int id;
	struct node* next;
} node;

// takes every args
///////////////////
typedef struct s_inputs
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat; //optional
} t_inputs;

// so many forks
// one for every philosopher
////////////////////////////
/* typedef struct s_spork
{
	int		id;
	int		nbr;
	struct	s_spork *next;
} t_spork; */

// inputs.c
///////////
void	args_manager(t_inputs *args, int argc, char *argv[]);

// utils.c
//////////
int		ft_atoi(const char *str);

#endif
