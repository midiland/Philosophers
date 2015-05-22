/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_circular.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:34:54 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/06 14:54:25 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circular.h"
#include <unistd.h>

t_list_circular			*init_list(void (*on_destruct)(t_list *))
{
	t_list_circular		*tmp;

	tmp = NULL;
	tmp = (t_list_circular *)malloc(sizeof(t_list_circular));
	if (tmp == NULL)
	{
		write(2, "fail to malloc list\n", 20);
	}
	else
	{
		tmp->begin = NULL;
		tmp->end = NULL;
		tmp->current = NULL;
		tmp->on_destruct = on_destruct;
		tmp->count = 0;
	}
	return (tmp);
}

t_list					*init_t_list(void *c)
{
	t_list				*tmp;

	tmp = NULL;
	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->content = c;
	}
	return (tmp);
}
