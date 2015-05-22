/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_circular.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:37:18 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/07 16:44:25 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circular.h"

static void	remove_first(t_list_circular *lst_c, t_list *lst)
{
	if (lst == lst_c->end)
	{
		lst_c->end = NULL;
		lst_c->begin = NULL;
	}
	else
		lst_c->begin = lst->next;
}

static void	remove_end(t_list_circular *lst_c, t_list *lst)
{
	if (lst == lst_c->begin)
	{
		lst_c->end = NULL;
		lst_c->begin = NULL;
	}
	else
		lst_c->end = lst->prev;
}

int			remove_c_destroy(t_list_circular *lst_c, t_list *lst)
{
	if (lst_c == NULL || lst == NULL)
		return (FALSE);
	if (lst == lst_c->begin)
		remove_first(lst_c, lst);
	else if (lst == lst_c->end)
		remove_end(lst_c, lst);
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	if (lst_c->on_destruct)
		lst_c->on_destruct(lst);
	free(lst);
	lst = NULL;
	lst_c->count--;
	return (TRUE);
}

int			remove_c(t_list_circular *lst_c, t_list *lst)
{
	if (lst_c == NULL || lst == NULL)
		return (FALSE);
	if (lst == lst_c->begin)
		remove_first(lst_c, lst);
	else if (lst == lst_c->end)
		remove_end(lst_c, lst);
	lst->prev->next = lst->next;
	lst->next->prev = lst->prev;
	lst_c->count--;
	return (TRUE);
}

void		clean(t_list_circular *lst_c)
{
	if (lst_c == NULL || lst_c->begin == NULL)
		return ;
	while (lst_c->begin)
		remove_c_destroy(lst_c, lst_c->begin);
}
