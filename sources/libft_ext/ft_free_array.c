/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:30:31 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/01 16:22:21 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ext.h"

void	ft_free_array(char **array)
{
	int		i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
