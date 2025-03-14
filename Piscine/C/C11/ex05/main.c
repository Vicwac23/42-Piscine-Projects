#include "libvic.h"

void	ft_assign_funs(int (*optab[])(int, int))
{
	optab[0] = sum;
	optab[1] = substract;
	optab[2] = multiply;
	optab[3] = divide;
	optab[4] = modulo;
}

int	ft_recon_op(char *c)
{
	if (*c == '+')
		return (0);
	else if (*c == '-')
		return (1);
	else if (*c == '*')
		return (2);
	else if (*c == '/')
		return (3);
	else if (*c == '%')
		return (4);
	return (-1);
}

int	ft_apply_fun(int a, int b, int (*f)(int, int))
{
	return (f(a, b));
}

int	zero_error(int b, int op)
{
	if (b == 0 && op == 3)
	{
		write(1, "Stop : division by zero", 23);
		return (1);
	}
	else if (b == 0 && op == 4)
	{
		write(1, "Stop : modulo by zero", 21);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	(*optab[5])(int, int);
	int	op;
	int	sol;
	int	a;
	int	b;

	sol = 0;
	ft_assign_funs(optab);
	if (argc == 4)
	{
		op = ft_recon_op(argv[2]);
		if (op == -1)
		{
			ft_putnbr(0);
			return (0);
		}
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (zero_error(b, op))
			return (0);
		sol = ft_apply_fun(a, b, optab[op]);
		ft_putnbr(sol);
	}
	return (0);
}
