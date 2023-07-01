/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:06:41 by mayan             #+#    #+#             */
/*   Updated: 2023/01/31 16:36:05 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putuns(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

// int main()
// {
// 	printf("%d", ft_putuns(-1000));
// }
