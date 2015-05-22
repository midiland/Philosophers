/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:56:20 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/22 12:51:26 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>

# define NB_PHILO 7
# define MAX_LIFE 100
# define EAT_T 20
# define REST_T 20
# define THINK_T 20
# define TIMEOUT 200
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
	pthread_t		thread;
}					t_philo;

typedef struct		s_table
{
	t_philo			philo[NB_PHILO];
	MUTEX			stick[NB_PHILO];
}					t_table;



#endif
