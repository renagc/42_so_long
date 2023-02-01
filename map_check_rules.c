/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:13:35 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/01 21:39:15 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*le o mapa e calcula o numero de linhas*/
static char	**ft_map_to_array(char *path)
{
	int		fd;
	char	*file;
	char	*next_line;
	char	*line_tmp;
	char	**map_array;

	fd = open(path, O_RDONLY);
	if (fd < 3)
		return (NULL);
	file = ft_calloc(1, 1);
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			break ;
		line_tmp = ft_strjoin(file, next_line);
		free(file);
		free(next_line);
		file = line_tmp;
	}
	close (fd);
	map_array = ft_split(file, '\n');
	free(file);
	return (map_array);
}

/*verifica os caracteres e se existe player, exit e key*/
static void	ft_check_map_chars(void **mlx, t_map *map)
{
	int			i;
	int			j;
	t_symbol	chars;

	i = 0;
	chars.exit = 0;
	chars.player = 0;
	chars.key = 0;
	while (map->array[++i] && i < (map->size.y - 1))
	{
		j = 0;
		while (map->array[i][++j] && j < (map->size.x - 1))
		{
			if (!ft_iscinstr("01PCE", map->array[i][j]))
				ft_free_close_map(mlx, map);
			else if (map->array[i][j] == 'E')
				chars.exit += 1;
			else if (map->array[i][j] == 'P')
				chars.player += 1;
			else if (map->array[i][j] == 'C')
				chars.key += 1;
		}
	}
	if (chars.player != 1 || chars.exit != 1 || chars.key == 0)
		ft_free_close_map(mlx, map);
}

static void	ft_check_map_walls(void **mlx, t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (map->array[++i])
	{
		j = -1;
		while (map->array[i][++j] && j < map->size.x)
		{
			if ((i == 0 || i == (map->size.y - 1)) && map->array[i][j] != '1')
				ft_free_close_map(mlx, map);
			else if ((j == 0 || j == (map->size.x - 1))
				&& map->array[i][j] != '1')
				ft_free_close_map(mlx, map);
		}
	}
}

/*verifica se é quadrado e se todas as linhas tem o mesmo tamanho*/
static void	ft_check_map_size(void *mlx, t_map *map)
{
	int			i;
	int			j;

	i = -1;
	while (map->array[++i])
	{
		j = 0;
		while (map->array[i][j])
			j++;
		if ((j - 1) != map->size.x)
			ft_free_close_map(mlx, map);
	}
	if (i != map->size.y || map->size.x == map->size.y)
		ft_free_close_map(mlx, map);
}

t_map	ft_open_map(void **mlx, char *path)
{
	t_map	map;

	map.array = ft_map_to_array(path);
	if (!map.array || !map.array[0])
		ft_free_close_map(mlx, &map);
	map.size.x = ft_strlen(map.array[0]) - 1;
	map.size.y = 0;
	while (map.array[map.size.y])
		map.size.y++;
	ft_check_map_size(mlx, &map);
	ft_check_map_walls(mlx, &map);
	ft_check_map_chars(mlx, &map);
	ft_check_map_path(mlx, &map);
	return (map);
}
