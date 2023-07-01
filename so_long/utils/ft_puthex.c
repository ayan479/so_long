/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:19:51 by mayan             #+#    #+#             */
/*   Updated: 2023/01/31 18:54:41 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	int		len;
	char	*hex;

	len = 1;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (c == 'x')
		hex = "0123456789abcdef";
	if (n > 15)
		len += ft_puthex(n / 16, c);
	ft_putchar(hex[n % 16]);
	return (len);
}
