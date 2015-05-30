/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:56:20 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/27 18:08:39 by bcrespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <time.h>

# define NB_PHILO 7
# define MAX_LIFE 5
# define EAT_T 1
# define REST_T 1
# define THINK_T 1
# define TIMEOUT 60
# define H_LIFE ((MAX_LIFE / 2) * 1.5)
# define CRIT_LIFE ((MAX_LIFE / 2))
# define  MUTEX pthread_mutex_t

typedef enum		e_etat
{
	REST, THINK, EAT
}					t_etat;

typedef struct		s_philo
{
	int				neighbor_eat;
	time_t			time;
	int				etats;
	int				life;
	int				bagu_r;
	int				bagu_l;
	int				place;
	pthread_t		thread;
}					t_philo;

typedef struct		s_table
{
	t_philo			*philo;
	t_philo			*philo_next;
	int				ok;
	time_t			time_gen;
	time_t			time_deb;
	int				brack;
}					t_table;

void				wait_second(t_table *tab);
void				wait_time(t_table *table, int t);
int					get_stick(int nb_stick);
int					have_stick(t_table *table);
void				drop_think_s(t_table *tab, int bag_next);
void				lock_stick(MUTEX *stick, int i);
void				*check_state(void *table);

#endif
