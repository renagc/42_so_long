/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:03:41 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/08 12:12:18 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_key_input_check_wall(t_program *game, int keycode)
{
	int	x;
	int	y;

	x = game->player_position.x;
	y = game->player_position.y;
	if (keycode == key_right)
		x++;
	else if (keycode == key_left)
		x--;
	else if (keycode == key_up)
		y--;
	else if (keycode == key_down)
		y++;
	if (game->map.array[y][x] == '1')
		return (0);
	ft_putnbr_fd(++game->map.moves, 1);
	write(1, "\n", 1);
	return (1);
}

static void	ft_key_input_rm_key(t_program *game)
{
	int	x;
	int	y;

	x = game->player_position.x;
	y = game->player_position.y;
	if (game->map.array[y][x] == 'C')
		game->map.array[y][x] = '0';
}

static void	ft_key_input_quit(t_program *game)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	close;

	close = 1;
	j = -1;
	while (game->map.array[++j])
	{
		i = -1;
		while (game->map.array[j][++i])
		{
			if (game->map.array[j][i] == 'C')
				close = 0;
		}
	}
	x = game->player_position.x;
	y = game->player_position.y;
	if (game->map.array[y][x] == 'E' && close)
	{
		ft_free_img_and_win(game);
		ft_free_close_map(0, 0, &game->mlx, &game->map);
	}
}

int	ft_key_input(int keycode, t_program *game)
{
	mlx_clear_window(game->mlx, game->window.reference);
	if (keycode == key_esc)
	{
		ft_free_img_and_win(game);
		ft_free_close_map(0, 0, &game->mlx, &game->map);
	}
	else if (keycode == key_right && ft_key_input_check_wall(game, keycode))
		game->player_position.x += 1;
	else if (keycode == key_left && ft_key_input_check_wall(game, keycode))
		game->player_position.x -= 1;
	else if (keycode == key_down && ft_key_input_check_wall(game, keycode))
		game->player_position.y += 1;
	else if (keycode == key_up && ft_key_input_check_wall(game, keycode))
		game->player_position.y -= 1;
	ft_key_input_rm_key(game);
	ft_key_input_quit(game);
	ft_draw_background(game);
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->player.reference, game->player_position.x * 32,
		game->player_position.y * 32);
	return (0);
}
