/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 12:39:57 by bcrespin          #+#    #+#             */
/*   Updated: 2015/05/27 18:13:45 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

extern	MUTEX		stick[NB_PHILO];

void	lock_stick(MUTEX *stick, int i)
{
	pthread_mutex_lock(&(stick[i]));
}

int		get_stick(int nb_stick)
{
	if (!pthread_mutex_trylock(&stick[nb_stick]))
		return (1);
	return (0);
}

int		have_stick(t_table *table)
{
	if ((table->philo->bagu_r == 1 || table->philo->bagu_l == 1) \
			&& table->philo->life > H_LIFE)
		return (1);
	if (table->philo->bagu_r == 1 || table->philo->bagu_l == 1)
	{
		if ((table->philo->bagu_r == 1 && table->philo->bagu_l == 1))
			return (2);
		return (1);
	}
	else
		return (0);
}

void	drop_think_s(t_table *tab, int bag_next)
{
	if (tab->philo->bagu_l == 1)
	{
		pthread_mutex_unlock(&(stick[tab->philo->place]));
		tab->philo->bagu_l = 0;
	}
	if (tab->philo->bagu_r == 1)
	{
		pthread_mutex_unlock(&(stick[bag_next]));
		tab->philo->bagu_r = 0;
	}
}
