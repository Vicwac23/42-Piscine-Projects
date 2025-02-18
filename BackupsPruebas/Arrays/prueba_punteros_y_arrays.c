#include <unistd.h>

void	print_arr_backwards(char *last, char *first)
{
	while (last >= first)
	{
		write(1, last, 1);
		last--; //Movemos el puntero que apunta al último elemento hacia atrás.
	}
}

int	my_strlen(char *ptr)
{	
	int i;
	i = 0;
	while (*ptr != '\0')
	{
		i++;
		ptr++;
	}
	return (i);
}

int	main(void)
{
	char arr[] = "hola";

	int len = my_strlen(arr);
	
	char *last = arr + len - 1;

	print_arr_backwards(last, arr);

	return 0;
}

