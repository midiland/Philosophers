/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:50:12 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/22 13:05:19 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

void		init_philo(t_philo *philo)
{
	philo->etats = REST;    // rest c'est mieux
	philo->life = MAX_LIFE;
	philo->bagu_r = 1;
	philo->bagu_l = 1;
	philo->pthr = NULL;
}


int			main()
{
	int		i;
	t_table table;

	i = 0;

	while (i < NB_PHILO)
	{
		pthread_mutex_init(table.stick[i], NULL);
		init_philo(&(table.philo[i++]));
	}

	return (0);
}
