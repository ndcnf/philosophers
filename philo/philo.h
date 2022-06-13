/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:13:47 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/13 13:36:10 by nchennaf         ###   ########.fr       */
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
# define N_MEAL "FYI: every philosopher will eat until they're bored and die\n"
# define S_SLP "is sleeping\n"
# define S_EAT "is eating\n"
# define S_THK "is thinking\n"
# define S_RIP "is dead\n"
# define S_INIT "is not ready yet for this simulation\n"

// so many forks
// one for every philosopher
////////////////////////////
typedef struct s_spork
{
	int	id;
	int	status; //taken or available
} t_spork;

// defines a philospher
//////////////////////////////
typedef struct s_philo
{
	int	id;
	int	meals_nbr;
	int	status; //is eating, is sleeping, is thinking or is dead
	t_spork	*fork;
} t_philo;

// takes every args
///////////////////
typedef struct s_inputs
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat; //arg is optional, to take into acount isn't
} t_inputs;



// the almighty structure ???
/////////////////////////
// typedef struct s_sim
// {
	
// } t_sim;

// philo.c
//////////
void	philo_status(t_philo *head);

// inputs.c
///////////
void	args_manager(t_inputs *args, int argc, char *argv[]);

// init.c
/////////
void	init_args(t_inputs *args);
void	init_sim(t_philo *phi);

// checks.c
///////////
void	check_args(int argc, char *argv[], t_inputs *args);

// utils.c
//////////
int		ft_atoi(const char *str);
void	ft_putstr(char *s);

#endif
