/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:05:03 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:05:03 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdelc(const char *s, char c)
{
	int		i;
	int		j;
	char	*ret;

	j = 0;
	i = 0;
	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (ret)
	{
		while (s[j])
		{
			if (s[j] != c)
				ret[i++] = s[j++];
			else if (s[j - 1] == '\\')
				ret[i - 1] = s[j++];
			else
				j++;
		}
		ret[i] = '\0';
		return (ret);
	}
	else
		return ((char *)s);
}
