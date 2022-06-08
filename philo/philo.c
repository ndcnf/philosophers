/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/07 14:17:53 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Pour l'instant, cette fonction n'est la qu'a titre d'exemple pour les listes chaines mais peut etre utilisee reellement apres
/* void	philo_status(t_philo *head)
{
	t_philo	*tempura;

	tempura = head;
	while (tempura != NULL)
	{
		printf("Philo num %d\n", tempura->id);
		tempura = tempura->next;
	}
}

t_philo	*new_philo_arrived(int value)
{
	t_philo	*res;

	res = malloc(sizeof(t_philo));
	res->
} */

int	main(int argc, char *argv[])
{
	//t_inputs	args;
	node		head;

	(void)argc;
	(void)argv;
	//args_manager(&args, argc, argv);
	printf("quoi...?");
	head.id = 15;
	printf("ola");
	head.next->next = malloc(sizeof(node));
	printf("postmalloc");
	head.next->id = -2;
	head.next->next = NULL;
	//t_philo	philo1;				//uniquement pour exemple avec trois philos
	//t_philo	philo2;				//ce code est seulement pour illustrer
	//t_philo	philo3;				//faudra le supprimer ensuite
/* 	t_philo *head;

	//LES LIENS DE LA LISTE CHAINEE SE FONT ICI - UNIQUEMENT EXEMPLE, faire une boucle correcte en vrai
	//head = &philo1;				//definit quel est le premier philo
	//philo1.next = &philo2;		//definit le second philo
	//philo2.next = &philo3;		//definit le troisieme philo
	//philo3.next = NULL;			//definit que c'est le dernier philo, il n'y en a pas de suivant
	printf("hello world\n");		//Juste pour afficher quelque chose et voir qu'on fait qqch
	philo_status(head); */

	printf("first : %d\n", head.id);
	printf("second : %d\n", head.next->id);
	free(head.next);
	return (0);
}
