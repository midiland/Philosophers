/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_circular.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 14:48:00 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/07 16:20:52 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circular.h"

void		*pop(t_list_circular *lst_c)
{
	t_list	*tmp;
	void	*tmp_c;

	tmp = lst_c->begin;
	tmp_c = lst_c->end->content;
	remove_c(lst_c, lst_c->begin);
	free(tmp);
	return (tmp_c);
}

void		*pop_back(t_list_circular *lst_c)
{
	t_list	*tmp;
	void	*tmp_c;

	tmp_c = lst_c->end->content;
	tmp = lst_c->end;
	remove_c(lst_c, lst_c->end);
	free(tmp);
	return (tmp_c);
}
