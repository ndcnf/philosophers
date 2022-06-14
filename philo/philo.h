/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:13:47 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/14 17:19:46 by nchennaf         ###   ########.fr       */
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

// so many forks
// one for every philosopher
////////////////////////////
typedef struct s_sporks
{
	int	id;
	int	status; //taken or available
} t_sporks;

// defines a philospher
//////////////////////////////
typedef struct s_philos
{
	int			id;
	int			meals_nbr;
	int			status; //is eating, is sleeping, is thinking or is dead
	int			timestamp;
	//t_spork	*fork; //not sure
} t_philos;

// takes every args
///////////////////
typedef struct s_inputs
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat; //arg is optional, to take into account isn't
} t_inputs;



// the almighty structure ???
/////////////////////////
// typedef struct s_sim
// {
//	int	timestamp;
	
// } t_sim;

// philo.c
//////////
void	philo_status(t_philo *head);

// inputs.c
///////////
void	args_manager(t_inputs *args, int argc, char *argv[]);
void	fork_manager(&args, &fk);

// init.c
/////////
void	need_space(t_inputs *args, t_philo *phi, t_spork *fk);
void	init_args(t_inputs *args);
void	init_sim(t_philo *phi, t_spork *fk);

// checks.c
///////////
void	errorminator(char *s);
void	check_args(int argc, char *argv[]);

//time.c
////////
void time_usec(void); // type and arg to do

// utils.c
//////////
int		ft_atoi(const char *str);
void	ft_putstr(char *s);

#endif
