/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_circular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:43:58 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/07 15:27:31 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circular.h"

void	swap(t_list *a, t_list *b)
{
	void	*tmp;

	if (a == b)
		return ;
	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

t_list	*find(t_list_circular *lst_c, void *to_find, int (*f)(void *, t_list *))
{
	t_list	*tmp;

	if (lst_c == NULL || f == NULL || lst_c->begin == NULL)
		return (NULL);
	if (f(to_find, lst_c->begin))
		return (lst_c->begin);
	tmp = lst_c->begin->next;
	while (tmp != lst_c->begin)
	{
		if (f(to_find, tmp))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*get_i_elem(t_list_circular *lst_c, int n)
{
	t_list	*tmp;
	int		i;

	i = 1;
	if (lst_c == NULL || lst_c->begin == NULL || n >= lst_c->count)
		return (NULL);
	if (n == 0)
		return (lst_c->begin);
	tmp = lst_c->begin->next;
	while (tmp != lst_c->begin && i != n)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
