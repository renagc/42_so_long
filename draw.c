/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:06:49 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/01 17:52:38 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_chars	ft_get_char_img(t_program *game)
{
	t_chars	chars;

	chars.key = ft_new_xpm_img(game->mlx, "textures/keys.xpm");
	chars.floor = ft_new_xpm_img(game->mlx, "textures/floor.xpm");
	chars.exit = ft_new_xpm_img(game->mlx, "textures/exit.xpm");
	chars.wall = ft_new_xpm_img(game->mlx, "textures/wall.xpm");

	return (chars);
}

void	ft_free_all(t_program *game)
{
	mlx_destroy_image(game->mlx, game->map.chars.key.reference);
	mlx_destroy_image(game->mlx, game->map.chars.floor.reference);
	mlx_destroy_image(game->mlx, game->map.chars.exit.reference);
	mlx_destroy_image(game->mlx, game->map.chars.wall.reference);
	mlx_destroy_image(game->mlx, game->player.reference);
	mlx_destroy_window(game->mlx, game->window.reference);
	mlx_destroy_display(game->mlx);
}

void	ft_draw_background(t_program *game)
{
	int		x;
	int		y;

	y = -1;
	while (game->map.array[++y])
	{
		x = -1;
		while (game->map.array[y][++x])
		{
			if (game->map.array[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window.reference,
					game->map.chars.wall.reference, x * 64, y * 64);
			else
				mlx_put_image_to_window(game->mlx, game->window.reference,
					game->map.chars.floor.reference, x * 64, y * 64);
			if (game->map.array[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window.reference,
					game->map.chars.exit.reference, x * 64, y * 64);
			else if (game->map.array[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window.reference,
					game->map.chars.key.reference, x * 64, y * 64);
		}
	}
}
