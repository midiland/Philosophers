/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:50:12 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/22 14:28:58 by apantiez         ###   ########.fr       */
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
	while (((t_table *)table)->philo->life > 0 && ((t_table *)table)->time < TIMEOUT)
	{
		usleep(400);
		((t_table *)table)->time += 1;
		((t_table *)table)->philo->life -= 1;
		ft_printf("life = %d, time = %d, place = %d\n", ((t_table *)table)->philo->life, ((t_table *)table)->time, ((t_table *)table)->philo->place);
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
		pthread_create(&(table[i].philo->thread), NULL, check_state, (void*)&(table[i]));
		pthread_join(table[i].philo->thread, NULL);
		i++;
	}
	return (0);
}
