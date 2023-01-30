/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscinstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:50:41 by parallels         #+#    #+#             */
/*   Updated: 2022/11/28 16:01:26 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ext.h"

int	ft_iscinstr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
