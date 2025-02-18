/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:43:27 by victmore          #+#    #+#             */
/*   Updated: 2025/02/02 18:45:26 by victmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	set_char(int x, int y, int i, int j) // -------> Elegir Caracter a Escribir
{
	if ((i == 0) && (j == 0)) // Arriba Izq
		ft_putchar('o');
	else if ((i == x) && (j == 0)) // Arriba Der
		ft_putchar('o');
	else if ((i == 0) && (j == y)) // Abajo Izq
		ft_putchar('o');
	else if ((i == x) && (j == y)) // Abajo Der
		ft_putchar('o');
	else if ((i == 0) || (i == x)) // Lados Verticales
		ft_putchar('|');
	else if ((j == 0) || (j == y)) // Lados Horizontales
		ft_putchar('-');
	else
		ft_putchar(' '); // Relleno (vacio -> espacios)
}

void	rush(int x, int y) // -----------------------> Moverse por el Cuadrado
{	
	if (x < 0)  // Comprobar números en Negativo
		x = -x;
	if (y < 0)
		y = -y;

	int i;
	int j;
	j = 0;

	while (j < y) // y == Alto Total
	{	
		i = 0;
		while (i < x) // x == Ancho Total
		{
			set_char(x - 1, y - 1, i, j); // Vamos a la función 'set_char'
			i++;
		}
		ft_putchar('\n'); // Escribe un Salto de Línea
		j++;
	}
}
