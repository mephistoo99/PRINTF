#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a = 11;
	int b = 11;
	int c = ft_printf("or_printf : %p %p\n",&a,&b);
	int d = printf("ft_printf : %p %p\n",&a,&b);
	printf("originel : %d\nft : %d\n",c ,d);
}