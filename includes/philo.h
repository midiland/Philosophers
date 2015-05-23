/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:56:20 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/22 14:16:17 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>

# define NB_PHILO 7
# define MAX_LIFE 100
# define EAT_T 5
# define REST_T 2
# define THINK_T 1
# define TIMEOUT 100
# define  MUTEX pthread_mutex_t

typedef enum		e_etat
{
	EAT, REST, THINK
}					t_etat;

typedef struct		s_philo
{
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
	unsigned int	time;
}					t_table;



#endif
