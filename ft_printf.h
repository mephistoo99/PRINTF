/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaarou <mchaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:17:45 by mchaarou          #+#    #+#             */
/*   Updated: 2026/11/15 16:23:09 by mchaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr_base(long nbr, char *base, int base_len, char spf);
int		ft_putstr(const char *str);
int		ft_putchar(const char c);
char	*ft_strchr(const char *s, int c);

#endif