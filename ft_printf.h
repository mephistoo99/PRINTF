#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int     ft_putnbr_base(long nbr, char *base, int base_len, char spf);
int 	ft_putstr(const char *str);
int 	ft_putchar(const char c);
char	*ft_strchr(const char *s, int c);

#endif