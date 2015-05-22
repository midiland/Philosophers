/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_circular.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:45:59 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/06 15:00:26 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circular.h"

int			ipush(t_list_circular *lst_c, void *ptr)
{
	t_list	*tmp;

	tmp = NULL;
	if ((tmp = init_t_list(ptr)) != NULL)
		push(lst_c, tmp);
	else
		return (FALSE);
	return (TRUE);
}

int			ipush_back(t_list_circular *lst_c, void *ptr)
{
	t_list	*tmp;

	tmp = NULL;
	if ((tmp = init_t_list(ptr)) != NULL)
		push_back(lst_c, tmp);
	else
		return (FALSE);
	return (TRUE);
}

int			push(t_list_circular *lst_c, t_list *lst)
{
	if (lst_c == NULL || lst == NULL)
		return (FALSE);
	if (lst_c->begin == NULL)
	{
		lst_c->begin = lst;
		lst_c->end = lst;
		lst->next = lst;
		lst->prev = lst;
	}
	else
	{
		lst->next = lst_c->begin;
		lst->prev = lst_c->end;
		lst_c->begin->prev = lst;
		lst_c->begin = lst;
		lst_c->end->next = lst;
	}
	lst_c->count++;
	return (TRUE);
}

int			push_back(t_list_circular *lst_c, t_list *lst)
{
	if (lst_c == NULL || lst == NULL)
		return (FALSE);
	if (lst_c->begin == NULL)
	{
		lst_c->begin = lst;
		lst_c->end = lst;
		lst->next = lst;
		lst->prev = lst;
	}
	else
	{
		lst->prev = lst_c->end;
		lst->next = lst_c->begin;
		lst_c->end->next = lst;
		lst_c->end = lst;
		lst_c->begin->prev = lst;
	}
	lst_c->count++;
	return (TRUE);
}
