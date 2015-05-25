/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:56:20 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/25 15:59:00 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <time.h>

# define NB_PHILO 7
# define MAX_LIFE 10
# define EAT_T 3
# define REST_T 5
# define THINK_T 2
# define TIMEOUT 50
# define  MUTEX pthread_mutex_t

typedef enum		e_etat
{
	EAT, REST, THINK
}					t_etat;

typedef struct		s_philo
{
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
	int				ok;
	time_t			time_gen;
	time_t			time_deb;
}					t_table;



#endif
