/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaarou <mchaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:20:47 by mchaarou          #+#    #+#             */
/*   Updated: 2026/11/10 18:27:06 by mchaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_spf(const char c, va_list ap)
{
    int check;

    check = 0;
    if (c == 'c')
        check = ft_putchar(va_arg(ap, int));
    else if (c == '%')
        check = ft_putchar('%');
    else if (c == 's')
        check = ft_putstr(va_arg(ap, char *));
    else if (c == 'd' || c == 'i')
        check = ft_putnbr_base(va_arg(ap, int), "0123456789", 10, c);
    else if (c == 'u')
        check = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789", 10, c);
    else if (c == 'x')
        check = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", 16, c);
    else if (c == 'X')
        check = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", 16, c);
    else if (c == 'p')
        check = ft_putnbr_base((long)va_arg(ap, unsigned long), "0123456789abcdef", 16, c);
    return (check);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    int     count;
    int     guard;
    size_t  i;

    if (!str)
        return (-1);
    i = 0;
    count = 0;
    va_start(ap, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1] && ft_strchr("cspdiuxX%", str[i + 1]))
            guard = print_spf(str[++i], ap);
        else
            guard = ft_putchar(str[i]);
        if (guard == -1)
        {
            va_end(ap);
            return (-1);
        }
        count += guard;
        ++i;
    }
    va_end(ap);
    return (count);
}