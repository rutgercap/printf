#include "ft_printf/ft_printf.h"

int main(void)
{
	int i = 100;
	char c = 'c';
	char *str = "This is a string";

	printf("|%i|\n", i);
	printf("|%10i|\n", i);
	printf("|%-10i|\n", i);
	printf("|%010i|\n", i);
	printf("|%10i|\n", i);
	printf("|% 10i|\n", i);
	printf("|%-10i|\n", i);
	printf("|%010.5i|\n", i);
	printf("|%0*.*i|\n", 100, 3, i);
	printf("|%c|\n", c);
	printf("|%10c|\n", c);
	printf("|%c|\n", c);
	printf("|%50s|\n", str);
	printf("|-----------------------------------------|\n");

	ft_printf("hello: %% , test: %%, again %%");
}