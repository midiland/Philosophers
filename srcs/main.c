/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:50:12 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/26 11:26:36 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"
#include "libft.h"


t_philo			philo[NB_PHILO];
MUTEX			stick[NB_PHILO];

void		wait_second(t_table *tab)
{
	time_t	time_a;

	time_a = time(NULL);
	while (1)
	{
		if (((time_a - tab->time_gen)) >= 1)
			return ;
		else
		{
			time_a = time(NULL);
			usleep(20);
		}
	}
}

void		init_philo(t_philo *philo, int place)
{
	philo->etats = THINK;
	philo->life = MAX_LIFE;
	philo->bagu_r = 0;
	philo->bagu_l = 1;
	philo->place = place;
	philo->neighbor_eat = 0;
}

void		wait_time(t_table *table, int t)
{
	while (1)
	{
		if (table->time_gen >= (table->philo->time + t))
			return ;
		else
			usleep(10);
	}
}

int			have_stick(t_table *table)
{
	if (table->philo->bagu_r == 1 && table->philo->bagu_l == 1)
		return (2);
	else if (table->philo->bagu_r == 1 || table->philo->bagu_l == 1)
		return (1);
	else
		return (0);
}

int		get_stick(int nb_stick)
{
	if (!pthread_mutex_trylock(&stick[nb_stick]))
		return (1);
	return (0);
}

void		*check_state(void *table)
{
	t_table	*tab;
	int		bag_next;

	tab = (t_table *)table;
	if (tab->philo->place == (NB_PHILO - 1))
		bag_next = 0;
	else
		bag_next = tab->philo->place + 1;
	while (tab->brack)//(tab->time_deb + TIMEOUT) > tab->time_gen && tab->philo->life >= 0)
	{
		tab->philo->time = time(NULL);
		if (tab->philo->life != MAX_LIFE && get_stick(bag_next))
				tab->philo->bagu_r = 1;
		if (tab->philo->life != MAX_LIFE && get_stick(tab->philo->place))
			tab->philo->bagu_l = 1;
		if (tab->philo->life <= 5)
			tab->philo_next->neighbor_eat = 1;
		else if (tab->philo->life <= 3)
			tab->philo_next->neighbor_eat = 2;
		else
			tab->philo_next->neighbor_eat = 0;
		if (have_stick(table) == 1)
		{
			tab->philo->etats = THINK;
			if (tab->philo->bagu_l == 1)
				pthread_mutex_unlock(&(stick[tab->philo->place]));
			else if (tab->philo->bagu_r == 1)
				pthread_mutex_unlock(&(stick[bag_next]));
			if (tab->philo->neighbor_eat == 2)
			{
				usleep(15);
				tab->philo->bagu_l = 0;
				tab->philo->bagu_r = 0;
			}
			if (tab->philo->neighbor_eat == 1)
			{
				usleep(5);
				tab->philo->bagu_l = 0;
				tab->philo->bagu_r = 0;
			}
			wait_time(tab, THINK_T);
			tab->philo->life -= THINK_T;
			tab->philo->bagu_l = 0;
			tab->philo->bagu_r = 0;
		}
		else if (have_stick(table) == 2)
		{
			tab->philo->etats = EAT;
			wait_time(tab, EAT_T);
			tab->philo->life = MAX_LIFE;
			usleep(5);
			pthread_mutex_unlock(&(stick[tab->philo->place]));
			pthread_mutex_unlock(&(stick[bag_next]));
			tab->philo->bagu_l = 0;
			tab->philo->bagu_r = 0;
			//add repot
		}
		else
		{
			tab->philo->etats = REST;
			wait_time(tab, REST_T);
			tab->philo->life -= REST_T;
		}
	}
	sleep(5);
	return (table);
}

void		lock_stick(MUTEX *stick, int i)
{
	pthread_mutex_lock(&(stick[i]));
}

void		print_etat(t_table *tab)
{
	if (tab->philo->etats == EAT)
		ft_printf("\033[36m --  EAT  -- \033[0m\n");
	else if (tab->philo->etats == THINK)
		ft_printf("\033[31m -- THINK -- \033[0m\n");
	else if (tab->philo->etats == REST)
		ft_printf("\033[32m --  REST -- \033[0m\n");
}

int			main()
{
	int		i;
	t_table table[NB_PHILO];
	int		life;

	i = 0;
	life = 0;
	while (i < NB_PHILO)
	{
		pthread_mutex_init(&(stick[i]), NULL);
		lock_stick(stick, i);
		init_philo(&philo[i], i);
		table[i].philo = &philo[i];
		table[i].brack = 1;
		if (i == (NB_PHILO - 1))
			table[i].philo_next = &philo[0];
		else
			table[i].philo_next = &philo[i + 1];
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
	while ((table[0].time_gen - table[0].time_deb) < TIMEOUT && !life )
	{
		wait_second(&table[0]);
		i = 0;
		ft_printf("\n");
		while (i < NB_PHILO)
		{
			table[i].time_gen = time(NULL);
			ft_printf("life = %d, time = %d, place = %d, etat = %d, stick right = %d, stick left = %d", table[i].philo->life, (table[i].time_gen - table[i].time_deb), table[i].philo->place, table[i].philo->etats, table[i].philo->bagu_r, table[i].philo->bagu_l);
			print_etat(&table[i]);
			if (table[i].philo->life <= 0 && table[i].philo->etats != EAT)
				life = 1;
			i++;
		}
	}
	i = 0;
	while (i < NB_PHILO)
	{
		table[i].time_gen = time(NULL);
		table[i++].brack = 0;
	}
	i = 0;
	while (i < NB_PHILO)
	{
		usleep(5);
		if(pthread_detach(philo[i].thread))
			ft_printf("ERROR\n");
		i++;
	}
	return (0);
}
