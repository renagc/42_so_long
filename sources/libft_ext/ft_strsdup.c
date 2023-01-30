/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:07:21 by parallels         #+#    #+#             */
/*   Updated: 2022/11/30 14:49:04 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ext.h"

char	**ft_strsdup(char **s1)
{
	int		array_size;
	int		str_size;
	char	**scpy;

	array_size = 0;
	while (s1[array_size])
		array_size++;
	scpy = malloc(array_size * sizeof(char) + 1);
	if (!scpy)
		return (NULL);
	while (--array_size >= 0)
	{
		str_size = 0;
		while (s1[array_size][str_size] != '\0')
			str_size++;
		scpy[array_size] = malloc(str_size * sizeof(char) + 1);
		if (!scpy[array_size])
			return (0);
		while (str_size >= 0)
		{
			scpy[array_size][str_size] = s1[array_size][str_size];
			str_size--;
		}
	}
	return (scpy);
}
