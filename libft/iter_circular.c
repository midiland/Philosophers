/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_circular.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:40:03 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/07 15:55:16 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circular.h"

void		iter_c(t_list_circular *lst_c, void (*f)(t_list *))
{
	t_list	*tmp;

	if (lst_c == NULL || f == NULL || lst_c->begin == NULL)
		return ;
	f(lst_c->begin);
	tmp = lst_c->begin->next;
	while (tmp != lst_c->begin)
	{
		f(tmp);
		tmp = tmp->next;
	}
}

void		iter_rev_c(t_list_circular *lst_c, void (*f)(t_list *))
{
	t_list	*tmp;

	if (lst_c == NULL || f == NULL || lst_c->begin == NULL)
		return ;
	f(lst_c->end);
	tmp = lst_c->end->prev;
	while (tmp != lst_c->end)
	{
		f(tmp);
		tmp = tmp->prev;
	}
}
