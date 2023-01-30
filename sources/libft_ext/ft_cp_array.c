/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:55:54 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/01/28 19:33:30 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ext.h"

char	**ft_cp_array(char **array)
{
	char	**new_array;
	int		i;

	i = 0;
	while (array[i])
		i++;
	new_array = (char **)malloc((i + 1) * sizeof(char *));
	if (!new_array)
		return (NULL);
	new_array[i--] = NULL;
	while (i >= 0)
	{
		new_array[i] = ft_strdup(array[i]);
		i--;
	}
	return (new_array);
}