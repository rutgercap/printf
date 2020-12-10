#include "ft_printf/ft_printf.h"

int main(void)
{
	int i = 420;
	char c = 'c';
	char *str = "This is a string";
	char *small = "small";

	// printf("|%%|\n");
	// printf("|%10%|\n");
	// printf("|%-10%|\n");
	// printf("|%-010.10%|\n");
	// printf("|%i|\n", i);
	// printf("|%0i|\n", i);
	// printf("|%.0i|\n", i);
	// printf("|%.10i|\n", i);
	// printf("|%10i|\n", i);
	// printf("|%-10i|\n", i);
	// printf("|%010i|\n", i);
	// printf("|%10i|\n", i);
	// printf("|% 10i|\n", i);
	// printf("|%-10i|\n", i);
	// printf("|%010.5i|\n", i);
	// printf("|%0*.*i|\n", 100, 5, i);
	// printf("|%c|\n", c);
	// printf("|%10c|\n", c);
	// printf("|%c|\n", 0);
	// printf("|%c|\n", c);
	// printf("|%50s|\n", str);
	// printf("|%50.5s|\n", str);
	// printf("|% 10i|\n", i);
	printf("|-----------------------------------------|\n");
	printf("Normal printf\n");
	printf("%.5i\n", i);
	printf("% 10.5i\n", -i);
	printf("%.3i\n", -i);
	printf("%i\n", -i);
	printf("%.5c\n", c);
	printf("%.5s\n", str);
	printf("%.5x\n", i);
	printf("|-----------------------------------------|\n");
	ft_printf("Ft printf:\n");
	ft_printf("i: |%.5i|\n", i);
	ft_printf("i: |%.5i|\n", -i);
	ft_printf("i: |%.5i|\n", str);
	// ft_printf("hello: %% , test: %%, again %%");
}

// cspdiuxX%
// -0.*


// bonus: # +