/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_circular.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 16:14:29 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/07 15:21:32 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CIRCULAR_H
# define LIST_CIRCULAR_H
# include <stdlib.h>

# define FALSE 0
# define TRUE 1

typedef struct	s_list{
	void				*content;
	struct s_list		*prev;
	struct s_list		*next;
}				t_list;

typedef struct	s_list_circular
{
	t_list			*begin;
	t_list			*end;
	t_list			*current;
	void			(*on_destruct)(t_list *);
	int				count;
}				t_list_circular;

t_list_circular	*init_list(void (*on_destruct)(t_list *lst));
int				push(t_list_circular *lst_c, t_list *lst);
int				push_back(t_list_circular *lst_c, t_list *lst);
void			clean(t_list_circular *lst_c);
void			iter_c(t_list_circular *lst_c, void (*f)(t_list *));
void			iter_rev_c(t_list_circular *lst_c, void (*f)(t_list *));
int				remove_c(t_list_circular *lst_c, t_list *lst);
int				remove_c_destroy(t_list_circular *lst_c, t_list *lst);

t_list			*init_t_list(void *ptr);

int				ipush(t_list_circular *lst_c, void *ptr);
int				ipush_back(t_list_circular *lst_c, void *ptr);
t_list			*find(t_list_circular *lst_c, void *ptr,
		int (*f)(void *ptr, t_list *lst));
void			*pop(t_list_circular *lst_c);
void			*pop_back(t_list_circular *lst_c);
t_list			*get_i_elem(t_list_circular *lst_c, int n);

void			swap(t_list *a, t_list *b);

#endif
