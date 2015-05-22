/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:04:59 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:04:59 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*str1;
	char			*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (s1 && s2)
	{
		while (((str1[i] != '\0') && (n > i))\
			|| (((str2[i]) != '\0') && (n > i)))
		{
			if (str1[i] != str2[i])
				return ((unsigned char)str1[i] - (unsigned char)str2[i]);
			i++;
		}
	}
	return (0);
}
