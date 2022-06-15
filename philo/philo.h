/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:13:47 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 15:43:32 by nchennaf         ###   ########.fr       */
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

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define ERROR "Error\n"
# define ERR_ARGS "Wrong number of arguments\n"
# define ERR_TYPE "It should be better with numbers between 1 and not too many\n"
# define ERR_PHL "There should be 1 to many (but not TOO many) philosopher(s)\n"
# define ERR_TTS "The length of time should be positive and not exceed a certain time\n"
# define ERR_MEM "Couldn't allow enough memory\n"

# define S_FK "has taken a fork\n"
# define S_SLP "is sleeping\n"
# define S_EAT "is eating\n"
# define S_THK "is thinking\n"
# define S_RIP "died\n"

# define INIT 0
# define AVAIL 1
# define UNAVAIL 2

# define SLEEPS 1
# define EATS 2
# define THINKS 3
# define DIES 4

// takes every args
///////////////////
typedef struct s_inputs
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
} t_inputs;

// defines a philospher
//////////////////////////////
typedef struct s_philos
{
	int			id;
	int			meals_nbr;
	int			status; //is eating, is sleeping, is thinking or is dead
	int			last_meal; //when was their last meal?
	pthread_t	phi;
	t_inputs	*in;
} t_philos;

// philo.c
//////////



// inputs.c
///////////
void	args_manager(t_philos *phis, int argc, char *argv[]);
void	*philo_starter_pack(void *arg);

// init.c
/////////
void	need_space(t_philos *phis);
void	init_args(t_philos *phis);
// void	init_sim(t_philos *phis);

// checks.c
///////////
void	errorminator(char *s);
void	check_args(int argc, char *argv[]);

//time.c
////////
void	time_usec(); // type and arg to do

// utils.c
//////////
int		ft_atoi(const char *str);
void	ft_putstr(char *s);

#endif
