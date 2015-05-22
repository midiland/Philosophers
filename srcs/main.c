/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 13:15:47 by bcrespin          #+#    #+#             */
/*   Updated: 2015/05/22 13:51:04 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

void		init_philo(t_philo *philo)
{
	philo->etats = THINK;
	philo->life = MAX_LIFE;
	philo->bagu_r = 0;
	philo->bagu_l = 1;
	philo->thread = NULL;
}

void		*check_state(void *table)
{

	(void)(t_table *)table;

	ft_printf("ici\n");
	return (table);
}


int			main()
{
	int		i;
	t_table table;

	i = 0;

	while (i < NB_PHILO)
	{
		pthread_mutex_init(&(table.stick[i]), NULL);
		init_philo(&(table.philo[i]));
		pthread_create(&(table.philo[i].thread), NULL, check_state, (void*)&table);
		pthread_join(table.philo[i].thread, NULL);
		i++;
	}


	return (0);
}
