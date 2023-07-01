/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:14:41 by mayan             #+#    #+#             */
/*   Updated: 2023/02/01 15:39:04 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexpointer(unsigned long n)
{
	int		len;
	char	*hex;

	len = 1;
	hex = "0123456789abcdef";
	if (n > 15)
		len += ft_hexpointer(n / 16);
	ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_putpointer(unsigned long n)
{
	int	len;

	len = ft_putstr("0x");
	if (n == 0)
		len += ft_putchar('0');
	else
		len += ft_hexpointer(n);
	return (len);
}
