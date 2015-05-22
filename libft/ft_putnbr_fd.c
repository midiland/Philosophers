/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apantiez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 17:05:01 by apantiez          #+#    #+#             */
/*   Updated: 2014/05/23 17:05:01 by apantiez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define C ft_putchar_fd

int	ft_putnbr_fd(int n, int fd)
{
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n >= 0)
		{
			if (n >= 10)
				return (ft_putnbr_fd(n / 10, fd) + C(n % 10 + '0', fd));
			else
				return (ft_putchar_fd('0' + n, fd));
		}
		else
			return (ft_putchar_fd('-', fd) + ft_putnbr_fd(-n, fd));
	}
	else if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	else
		return (0);
	return (0);
}
