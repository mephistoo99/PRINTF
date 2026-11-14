/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaarou <mchaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:27:06 by mchaarou          #+#    #+#             */
/*   Updated: 2026/11/10 16:23:29 by mchaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(const char c)
{
    if (write(1, &c, 1) == -1)
        return (-1);
    return (1);
}

int ft_putstr(const char *str)
{
    int i;

    if (!str)
        return (ft_putstr("(null)"));
    i = 0;
    while (str[i])
    {
        if (write(1, &str[i], 1) == -1)
            return (-1);
        ++i;
    }
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    size_t i;

    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char *)(s + i));
        ++i;
    }
    if (s[i] == (char)c)
        return ((char *)(s + i));
    return (NULL);
}