/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:50:12 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/30 15:53:11 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"
#include "libft.h"
#include <stdio.h>

t_philo		g_philo[NB_PHILO];
MUTEX		stick[NB_PHILO];

void		init_philo(t_philo *g_philo, int place)
{
	g_philo->etats = THINK;
	g_philo->life = MAX_LIFE;
	g_philo->bagu_r = 0;
	g_philo->bagu_l = 1;
	g_philo->place = place;
	g_philo->neighbor_eat = 0;
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

void	sub_sub_main(t_table *table, int life, int i)
{
	while (((table[0].time_gen - table[0].time_deb) < TIMEOUT) && (life == 0) )
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
}

void		sub_main(t_table *table, int life, int i)
{
	i = 0;
	while (i < NB_PHILO)
	{
		pthread_create(&(g_philo[i].thread), NULL, check_state, (void*)&(table[i]));
		table[i].time_gen = time(NULL);
		i++;
	}
	sub_sub_main(table, life, i);
	i = 0;
	while (i < NB_PHILO)
	{
		table[i].time_gen = time(NULL);
		table[i++].brack = 0;
		usleep(15);
	}
	i = (NB_PHILO - 1);
	while (i >= 0)
	{
		if (pthread_detach(g_philo[i].thread))
			ft_printf("ERROR\n");
		i--;
	}
}

int			main()
{
	int		i;
	t_table *table;
	int		life;
	t_gen	gen;

	i = 0;
	life = 0;
	init_glfw(&gen);
	table = gen.table;
	while (i < NB_PHILO)
	{
		pthread_mutex_init(&(stick[i]), NULL);
		lock_stick(stick, i);
		init_philo(&g_philo[i], i);
		table[i].philo = &g_philo[i];
		table[i].brack = 1;
		if (i == (NB_PHILO - 1))
			table[i].philo_next = &g_philo[0];
		else
			table[i].philo_next = &g_philo[i + 1];
		table[i].time_deb = time(NULL);
		i++;
	}
	sub_main(table, life, i);
	return (0);
}
