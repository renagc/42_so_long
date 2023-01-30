/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:09:19 by rgomes-c          #+#    #+#             */
/*   Updated: 2022/11/27 16:53:41 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_lu(unsigned int n, unsigned int b, char x)
{
	int		na;

	na = 0;
	if (n > (b - 1))
		na += ft_putnbr_lu(n / b, b, x) + ft_putnbr_lu(n % b, b, x);
	else if (n < 10)
	{
		n = n + 48;
		na += ft_putchar(n);
	}
	else if (x == 'l')
	{
		n = n + 87;
		na += ft_putchar(n);
	}
	else if (x == 'u')
	{
		n = n + 55;
		na += ft_putchar(n);
	}
	return (na);
}
