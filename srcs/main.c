/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:50:12 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/25 15:57:52 by apantiez         ###   ########.fr       */
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

void		wait_time(t_table *table, int t)
{
	time_t	curent_time;

	curent_time = table->time_gen;
	while (1)
	{
		if (table->time_gen >= (table->philo->time + t))
			return ;
		else
		{
			if ((table->time_gen - curent_time) >= 1)
			{
				curent_time = table->time_gen;
				table->philo->life -= 1;
			}
			usleep(200);
		}
	}
}

int			have_stick(t_table *table)
{
	if (table->philo->bagu_r == 1 && table->philo->bagu_l == 1)
		return (1);
	else if (table->philo->bagu_r == 1 || table->philo->bagu_l == 1)
		return (2);
	else
		return (0);
}

void		*check_state(void *table)
{
	t_table	*tab;
	int		bag_next;
	int		error;

	tab = (t_table *)table;
	if (tab->philo->place == (NB_PHILO - 1))
		bag_next = 0;
	else
		bag_next = tab->philo->place + 1;
	while ((tab->time_deb + TIMEOUT) >= tab->time_gen)
	{
		tab->philo->time = time(NULL);
		if (have_stick(table) == 2)
		{
			tab->philo->etats = THINK;
			wait_time(tab, THINK_T);
			pthread_mutex_unlock(&(stick[tab->philo->place]));
			tab->philo->bagu_l = 0;
			tab->philo->bagu_r = 0;
		}
		else if (have_stick(table) == 1)
		{
			tab->philo->etats = EAT;
			tab->philo->life = MAX_LIFE;
			wait_time(tab, EAT_T);
			pthread_mutex_unlock(&(stick[tab->philo->place]));
			pthread_mutex_unlock(&(stick[bag_next]));
			((t_table *)table)->philo->bagu_l = 0;
			((t_table *)table)->philo->bagu_r = 0;
		}
		else
		{
			tab->philo->etats = REST;
			if (!(error = pthread_mutex_trylock(&(stick[tab->philo->place]))))
				tab->philo->bagu_l = 1;
			if (!(error = pthread_mutex_trylock(&(stick[bag_next]))))
				tab->philo->bagu_r = 1;
			if (error == 0)
				wait_time(tab, REST_T);
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
		table[i].time_deb = time(NULL);
		i++;
	}
	i = 0;
	while (i < NB_PHILO)
	{
		pthread_create(&(philo[i].thread), NULL, check_state, (void*)&(table[i]));
		table[i].time_gen = time(NULL);
		i++;
	}
	while (((int)(table[0].time_gen - table[0].time_deb)) <= TIMEOUT)
	{
		sleep(1);
		i = 0;
		ft_printf("\n\n");
		while (i < NB_PHILO)
		{
			table[i].time_gen = time(NULL);
			ft_printf("life = %d, time = %d, place = %d, etats = %d\n", table[i].philo->life, (table[i].time_gen - table[i].time_deb), table[i].philo->place, table[i].philo->etats);
			i++;
		}
	}
	return (0);
}
