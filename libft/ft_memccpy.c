/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:59 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:04:59 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2 && c && n)
	{
		while (i < n)
		{
			*((char *)s1 + i) = *((char *)s2 + i);
			if (*((char *)s2 + i) == (unsigned char)c)
				return ((char *)s1 + i + 1);
			i++;
		}
	}
	return (NULL);
}
