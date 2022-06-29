/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:13:47 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 14:23:12 by nchennaf         ###   ########.fr       */
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

# define RED "\001\033[1;91m\002"

# define ERROR "Error\n"
# define ERR_ARGS "Wrong number of arguments\n"
# define ERR_TYPE "Enter numbers between 1 and not too many\n"
# define ERR_PHL "There should be 1 to many (but not TOO many) philosopher(s)\n"
# define ERR_TTS "The length of time is invalid\n"
# define ERR_MEM "Couldn't allow enough memory\n"
# define ERR_THD "Something went wrong with the thread\n"

# define S_FK "has taken a fork\n"
# define S_SLP "is sleeping\n"
# define S_EAT "is eating\n"
# define S_THK "is thinking\n"
# define S_RIP "died\n"
# define S_RIP1 "died of solitude\n"

# define ALIVE 0
# define DEAD 1

# define FREE_BUFFET -1

# define NOTHING 0
# define SLEEPS 1
# define EATS 2
# define THINKS 3
# define DIES 4

// takes every args
///////////////////
typedef struct s_inputs
{
	int				n_philos;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_meals;
	size_t			t_sim;
	pthread_mutex_t	*fork;
}	t_inputs;

// defines a philospher
//////////////////////////////
typedef struct s_philos
{
	int			id;
	int			meals_nbr;
	int			status;
	int			last_meal; //when was their last meal?
	int			neighbour; // if *r_nghbr fails
	int			action; //is eating, is sleeping, is thinking or is dead
	pthread_t	phi;
	t_inputs	*in;
}	t_philos;

// inputs.c
///////////
void	args_manager(t_inputs *in, int argc, char *argv[]);
int		philo_starter_pack(t_philos **phis);
void	*the_routine(void *arg);

// init.c
/////////
int		need_space(t_philos **phis, int argc, char *argv[]);
void	init_philo(t_philos *phi);
// void	routine_du_mutex(phis);

// checks.c
///////////
int		errorminator(char *s);
int		check_args(int argc, char *argv[]);

//time.c
////////
size_t	timelord(void);

// utils.c
//////////
int		ft_atoi(const char *str);
void	ft_putstr(char *s);

// actions.c
////////////
// int		go_to_sleep(t_philos *phi);
int		eat_something(t_philos *phi);
// int		think_about_life(t_philos *phi);
// int		surprise_ur_dead(t_philos *phi);
int		please_wait(t_philos *phi, size_t future_t);

#endif
