#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...);

int	main()
{
	int a;

	printf("abc %c,%-5s,%p,%7.5d\n", 'A', "Hi", &a, 123);
	ft_printf("abc %c,%-5s,%p,%7.5d\n", 'A', "Hi", &a, 123);

	return (0);
}
