/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 13:15:47 by bcrespin          #+#    #+#             */
/*   Updated: 2015/05/22 14:25:12 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

#include <stdio.h>

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

int is_one_dead(t_table table)
{
	int i = 0;
	while (i < NB_PHILO)
	{
		if (table.philo[i].life == 0)
			return (1);
		i++;
	}
	return (0);
}

int			main()
{
	int		i;
	int		t;
	t_table table;

	i = 0;
	t = TIMEOUT;
	while (i < NB_PHILO)
	{
		pthread_mutex_init(&(table.stick[i]), NULL);
		init_philo(&(table.philo[i]));
		i++;
	}
	while (is_one_dead(table) == 0 && t > 0)
	{
		pthread_create(&(table.philo[i].thread), NULL, check_state, (void*)&table);
		pthread_join(table.philo[i].thread, NULL);
		printf("%d\n", t);
		t--;
	}
	return (0);
}
