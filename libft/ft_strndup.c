/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <apantiez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:31:17 by apantiez          #+#    #+#             */
/*   Updated: 2013/12/19 15:31:45 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char		*ft_strndup(const char *s1, int n)
{
	char	*ptr;
	char	*ret;

	ptr = (char *)malloc(n * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ret = ptr;
	while (n-- && *s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (ret);
}
