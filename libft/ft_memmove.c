/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:05:00 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:05:00 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!(s1 > s2 && s2 + n > s1))
		ft_memcpy(s1, s2, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*((char *)s1 + i) = *((char *)s2 + i);
		}
	}
	return (s1);
}
