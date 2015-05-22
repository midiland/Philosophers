/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:23:35 by apantiez          #+#    #+#             */
/*   Updated: 2013/12/01 17:37:02 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse(const char *s)
{
	char	*str;
	size_t	len_s;

	len_s = ft_strlen(s);
	str = ft_strnew(len_s);
	while (len_s)
	{
		str[len_s] = s[len_s];
		len_s--;
	}
	return (str);
}
