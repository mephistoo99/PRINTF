#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char *a = "hello";
	int b = 11;
	
	int x = 16;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	ft_printf("or_printf : %s %p\n",a,&a);
	printf("ft_printf : %s %p\n",a,&a);

	ft_printf("or_printf : %x %X\n",x,x);
	printf("ft_printf : %x %X\n",x,x);


}