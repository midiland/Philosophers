/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcrespin <bcrespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 11:47:31 by bcrespin          #+#    #+#             */
/*   Updated: 2015/10/13 13:15:16 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	wait_second(t_table *tab)
{
	time_t time_a;

	time_a = time(NULL);
	while (1)
	{
		if ((time_a - tab->time_gen) > 1)
			return ;
		else
		{
			time_a = time(NULL);
			usleep(20);
		}
	}
}

void	wait_time(t_table *table, int t)
{
	while (1)
	{
		if (table->time_gen >= (table->philo->time + t) || table->brack == 0)
			return ;
		else
			usleep(30);
	}
}
