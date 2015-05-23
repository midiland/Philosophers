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
}

void		wait_time(t_table *table)
{
	while (1)
	{
		if (table->ok == 1)
			return ;
	}
}

int			have_stick(t_table *table)
{
	if (table->philo->bagu_r == 1 || table->philo->bagu_l == 1)
		return (2);
	else if (table->philo->bagu_r == 1 && table->philo->bagu_l == 1)
		return (1);
	else
		return (0);

}

void		*check_state(void *table)
{
	while (1)
	{
		((t_table *)table)->ok = 0;
		wait_time((t_table *)table);
		((t_table *)table)->philo->life -= 1;
		ft_printf("stick = %d\n",have_stick(table));
		if (have_stick(table) == 2)
		{
			philo->etats = THINK;
			sleep(THINK_T);
			pthread_mutex_unlock(&(stick[((t_table *)table)->philo->place]));
			((t_table *)table)->philo->bagu_l = 0;
			((t_table *)table)->philo->bagu_r = 0;
		}
		else if (have_stick(table) == 1)
		{
			philo->etats = EAT;
			sleep(EAT_T);
		}
		else
		{
			philo->etats = REST;
			sleep(REST_T);
		}
	}
	pthread_exit(NULL);
	return (table);
}

void		lock_stick(MUTEX *stick, int i)
{
	pthread_mutex_lock(&(stick[i]));
}

int			main()
{
	int		i;
	t_table table[NB_PHILO];

	i = 0;
	while (i < NB_PHILO)
	{
		pthread_mutex_init(&(stick[i]), NULL);
		lock_stick(stick, i);
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
//			ft_printf("life = %d, time = %d, place = %d, etats = %d\n", table[i].philo->life, table[i].time, table[i].philo->place, table[i].philo->etats);
			table[i].ok = 1;
			table[i++].time += 1;
		}
	}
	return (0);
}
