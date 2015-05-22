/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:50:12 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/22 16:58:06 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"


t_philo			philo[NB_PHILO];
MUTEX			stick[NB_PHILO];

void		init_philo(t_philo *philo, int place)
{
	philo->etats = THINK;
	philo->life = MAX_LIFE;
	philo->bagu_r = 0;
	philo->bagu_l = 1;
	philo->place = place;
	philo->thread = NULL;
}

void		*check_state(void *table)
{
	while (1)
	{
		;//usleep(1000);
	}
	pthread_exit(NULL);
	return (table);
}


int			main()
{
	int		i;
	t_table table[NB_PHILO];

	i = 0;
	while (i < NB_PHILO)
	{
		pthread_mutex_init(&(stick[i]), NULL);
		init_philo(&philo[i], i);
		table[i].philo = &philo[i];
		table[i].time = 0;
		i++;
	}
	i = 0;
	while (i < NB_PHILO)
	{
		pthread_create(&(table[i].philo->thread), NULL, check_state, (void*)&(table[i]));
		i++;
	}
	while (table[0].time < TIMEOUT)
	{
		sleep(1);
		i = 0;
		while (i < NB_PHILO)
		{

			ft_printf("life = %d, time = %d, place = %d\n", table[i].philo->life, table[i].time, table[i].philo->place);
			table[i].time += 1;
			table[i++].philo->life -= 1;
		}
	}
	return (0);
}
