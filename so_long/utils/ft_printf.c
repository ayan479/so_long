/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:41:45 by mayan             #+#    #+#             */
/*   Updated: 2023/02/08 18:43:41 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_putpointer(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putuns(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'X')
		len += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check(str[++i], args);
		}
		else
		{
			len += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	printf("%s\n\n","character %c:");
// 	char c = 'c';
// 	ft_printf("%c\n", c);
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%c\n\n\n", c);

// 	printf("%s\n\n","pointer %p:");
// 	char *p = "1000000";
// 	ft_printf("%p\n", &p);
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%p\n\n\n", &p);

// 	printf("%s\n\n","string %s:");
// 	char *s = "striiiiiiiing";
// 	ft_printf("%s\n", s);
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%s\n\n\n", s);

// 	printf("%s\n\n","decimal %d:");
// 	char d = 123;
// 	ft_printf("%d\n", d);
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%d\n\n\n", d);

// 	printf("%s\n\n","integer %i:");
// 	int i = -123;
// 	ft_printf("%i\n", i);
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%i\n\n\n", i);

// 	printf("%s\n\n","unsigned %u:");
// 	int u = -123;
// 	ft_printf("%u\n", u);
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%u\n\n\n", u);

// 	printf("%s\n\n","hex x %x:");
// 	int x = -123;
// 	ft_printf("%x\n", x);
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%x\n\n\n", x);

// 	printf("%s\n\n","hex X %X:");
// 	int X = -123;
// 	ft_printf("%X\n", X);
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%X\n\n\n", X);

// 	printf("%s\n\n","percent sign %%:");
// 	ft_printf("%%\n");
// 	printf("%s\n%s\n","mine^^^","real↓↓↓");
// 	printf("%%\n\n\n");
// }
