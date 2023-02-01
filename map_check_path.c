/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:43:17 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/01 20:47:45 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_map_path_position(t_map *map, int x, int y)
{
	if (x > 0 && x < (map->size.x - 1) && y > 0 && y < (map->size.y - 1))
	{
		if (map->array[y][x] != '1')
		{
			if (map->array[y][x] != 'X')
			{
				map->array[y][x] = 'X';
				return (1);
			}
		}
	}
	return (0);
}

static void	ft_check_map_path_possible(t_map *map, int x, int y)
{
	if (ft_check_map_path_position(map, x - 1, y))
		ft_check_map_path_possible(map, x - 1, y);
	if (ft_check_map_path_position(map, x + 1, y))
		ft_check_map_path_possible(map, x + 1, y);
	if (ft_check_map_path_position(map, x, y - 1))
		ft_check_map_path_possible(map, x, y - 1);
	if (ft_check_map_path_position(map, x, y + 1))
		ft_check_map_path_possible(map, x, y + 1);
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

static void	ft_close_map_cp(t_map *map_cp)
{
	int	i;

	i = -1;
	while (map_cp->array[++i])
		free(map_cp->array[i]);
	free(map_cp->array);
}

void	ft_check_map_path(void **mlx, t_map *map)
{
	t_map			map_cp;
	t_vector		player_position;
	int				i;
	int				j;

	map_cp.array = ft_cp_array(map->array);
	map_cp.size.x = map->size.x;
	map_cp.size.y = map->size.y;
	player_position = ft_get_player_position(&map_cp);
	ft_check_map_path_possible(&map_cp, player_position.x, player_position.y);
	i = -1;
	while (map_cp.array[++i])
	{
		j = -1;
		while (map_cp.array[i][++j])
		{
			if (map_cp.array[i][j] == 'C' || map_cp.array[i][j] == 'E')
			{
				ft_close_map_cp(&map_cp);
				ft_free_map(mlx, map);
			}
		}
	}
	ft_close_map_cp(&map_cp);
}
