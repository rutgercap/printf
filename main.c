#include <stdio.h>
#include "ft_printf/ft_printf.h"

int main(void)
{
	int i = 100;
	char c = 'c';
	char *str = "This is a string";

	printf("%i\n", i);
	printf("%10i\n", i);
	printf("%10i\n", i);

}