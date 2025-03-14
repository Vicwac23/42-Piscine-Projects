// Only with pointers to functions: f(tab[i]) = (*f)(tab[i])
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = -1;
	while (++i < length)
		f(tab[i]);
}
