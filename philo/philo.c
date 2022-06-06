/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/06 12:43:59 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Pour l'instant, cette fonction n'est la qu'a titre d'exemple pour les listes chaines mais peut etre utilisee reellement apres
void	philo_status(philo_t *head)
{
	philo_t	*tempura;

	tempura = head;
	while (tempura != NULL)
	{
		printf("Philo num %d\n", tempura->num);
		tempura = tempura->next;
	}
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	//philo_t	philo1;				//uniquement pour exemple avec trois philos
	//philo_t	philo2;				//ce code est seulement pour illustrer
	//philo_t	philo3;				//faudra le supprimer ensuite
	philo_t *head;

	//LES LIENS DE LA LISTE CHAINEE SE FONT ICI - UNIQUEMENT EXEMPLE, faire une boucle correcte en vrai
	//head = &philo1				//definit quel est le premier philo
	//philo1.next = &philo2			//definit le second philo
	//philo2.next = &philo3			//definit le troisieme philo
	//philo3.next = NULL			//definit que c'est le dernier philo, il n'y en a pas de suivant
	printf("hello world\n");		//Juste pour afficher quelque chose et voir qu'on fait qqch

	return (0);
}