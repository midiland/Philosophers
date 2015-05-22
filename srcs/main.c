/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:50:12 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/22 11:57:10 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

void		init_philo(t_philo *philo)
{
	philo->etats = THINK;

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
