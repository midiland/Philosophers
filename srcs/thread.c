/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 13:55:37 by bcrespin          #+#    #+#             */
/*   Updated: 2015/05/30 14:57:18 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

extern	MUTEX		stick[NB_PHILO];

t_table	*life_n_stick(t_table *tab, int bag_next)
{
	if (tab->philo->life != MAX_LIFE && get_stick(bag_next))
		tab->philo->bagu_r = 1;
	if (tab->philo->life != MAX_LIFE && get_stick(tab->philo->place))
		tab->philo->bagu_l = 1;
	if (tab->philo->life <= CRIT_LIFE)
		tab->philo_next->neighbor_eat = 2;
	else if (tab->philo->life <= H_LIFE)
		tab->philo_next->neighbor_eat = 1;
	else
		tab->philo_next->neighbor_eat = 0;
	return (tab);
}

t_table	*ft_think(t_table *tab, int bag_next)
{
	tab->philo->etats = THINK;
	if (tab->philo->neighbor_eat == 2)
		drop_think_s(tab, bag_next);
	else if (tab->philo->neighbor_eat == 1)
		drop_think_s(tab, bag_next);
	wait_time(tab, THINK_T);
	tab->philo->life -= THINK_T;
	return (tab);
}

t_table	*ft_eat(t_table *tab, int bag_next)
{
	tab->philo->etats = EAT;
	tab->philo->life = MAX_LIFE;
	wait_time(tab, EAT_T);
	pthread_mutex_unlock(&(stick[tab->philo->place]));
	pthread_mutex_unlock(&(stick[bag_next]));
	tab->philo->bagu_l = 0;
	tab->philo->bagu_r = 0;
	return (tab);
}

t_table	*ft_rest(t_table *tab)
{
	tab->philo->etats = REST;
	wait_time(tab, REST_T);
	tab->philo->life -= REST_T;
	return (tab);
}

void	*check_state(void *table)
{
	t_table	*tab;
	int		bag_next;

	tab = (t_table *)table;
	if (tab->philo->place == (NB_PHILO - 1))
		bag_next = 0;
	else
		bag_next = tab->philo->place + 1;
	while (1)
	{
		tab->philo->time = time(NULL);
		tab = life_n_stick(tab, bag_next);
		if (have_stick(table) == 1 && tab->philo->etats != EAT)
			tab = ft_think(tab, bag_next);
		else if (have_stick(table) == 2 && tab->philo->etats != EAT)
			tab = ft_eat(tab, bag_next);
		else
			tab = ft_rest(tab);
		if (tab->brack == 0)
			while (1);
	}
	return (table);
}
