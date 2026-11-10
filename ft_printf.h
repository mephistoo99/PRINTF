#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_putnbr_base(ssize_t nbr, char *base, size_t len, char spf);
size_t	ft_putstr(const char *str);
size_t	ft_putchar(const char c);
char	*ft_strchr(const char *s, int c);

#endif