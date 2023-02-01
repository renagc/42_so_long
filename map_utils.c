/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:06:42 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/01 21:19:50 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_close_map(void **mlx, t_map *map)
{
	int		i;


	mlx_destroy_display(*mlx);
	free(*mlx);
	i = -1;
	if (map->array)
	{
		while (map->array[++i])
			free(map->array[i]);
		free(map->array);
	}
	exit(0);
}

t_vector	ft_get_player_position(t_map *map)
{
	int			i;
	int			j;
	t_vector	player;

	i = 0;
	while (map->array[i])
	{
		j = 0;
		while (map->array[i][j])
		{
			if (map->array[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
			}
			j++;
		}
		i++;
	}
	return (player);
}
