/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 10:56:20 by apantiez          #+#    #+#             */
/*   Updated: 2015/05/22 11:16:16 by apantiez         ###   ########.fr       */
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

typedef struct		s_philo
{
	int				etats;
	int				life;
	int				bagu_r;
	int				bagu_l;
	struct s_philo	*right;
	struct s_philo	*left;
}					t_philo;

typedef struct		s_table
{
	t_philo			philo[NB_PHILO];
	pthread_mutex_t	stick[NB_PHILO];
}					t_table;



#endif
