/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:05:05 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:05:05 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		save;

	i = 0;
	save = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			save = i;
		}
		i++;
	}
	if (c == 0)
	{
		return ((char *)&s[i]);
	}
	else if (save == -1)
	{
		return (NULL);
	}
	return ((char *)&s[save]);
}
