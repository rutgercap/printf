#include "ft_printf/ft_printf.h"

int main(void)
{
	int i = 100;
	char c = 'c';
	char *str = "This is a string";

	printf("|%%|\n");
	printf("|%10%|\n");
	printf("|%-10%|\n");
	printf("|%-010.10%|\n");
	printf("|%i|\n", i);
	printf("|%0i|\n", i);
	printf("|%.0i|\n", i);
	printf("|%.10i|\n", i);
	printf("|%10i|\n", i);
	printf("|%-10i|\n", i);
	printf("|%010i|\n", i);
	printf("|%10i|\n", i);
	printf("|% 10i|\n", i);
	printf("|%-10i|\n", i);
	printf("|%010.5i|\n", i);
	printf("|%0*.*i|\n", 100, 5, i);
	printf("|%c|\n", c);
	printf("|%10c|\n", c);
	printf("|%c|\n", 0);
	printf("|%c|\n", c);
	printf("|%50s|\n", str);
	printf("|%50.5s|\n", str);
	printf("|%#10i|\n", i);
	printf("|% 10i|\n", i);
	printf("|%+10c|\n", 'c');
	printf("|-----------------------------------------|\n");

	printf("hello: %% , test: %%, again %%");
	// ft_printf("hello: %% , test: %%, again %%");
}