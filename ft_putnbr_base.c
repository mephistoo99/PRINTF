/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaarou <mchaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:07:24 by mchaarou          #+#    #+#             */
/*   Updated: 2026/11/10 17:05:18 by mchaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_base(unsigned long num, char *base, unsigned long base_len)
{
    char str[21];
    int  count;
    int  i;

    if (num == 0)
        return (ft_putchar(base[0]));
    i = 0;
    while (num != 0)
    {
        str[i++] = base[num % base_len];
        num /= base_len;
    }
    count = 0;
    while (i--)
    {
        if (ft_putchar(str[i]) == -1)
            return (-1);
        count++;
    }
    return (count);
}

int print_ptr_prefix(long nbr)
{
    if (nbr == 0)
        return (ft_putstr("0x0"));
    return (ft_putstr("0x"));
}

int ft_putnbr_base(long nbr, char *base, int base_len, char spf)
{
    int           count;
    int           guard;
    unsigned long u_nbr;

    count = 0;
    if (spf == 'p')
    {
        guard = print_ptr_prefix(nbr);
        if (guard == -1 || nbr == 0)
            return (guard);
        count += guard;
    }
    u_nbr = (unsigned long)nbr;
    if ((spf == 'd' || spf == 'i') && nbr < 0)
    {
        if (ft_putchar('-') == -1)
            return (-1);
        count++;
        u_nbr = (unsigned long)(-(nbr + 1)) + 1;
    }
    guard = print_base(u_nbr, base, (unsigned long)base_len);
    if (guard == -1)
        return (-1);
    return (count + guard);
}