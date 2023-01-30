/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:03:41 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/01/30 13:42:35 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_input_check_wall(t_program *game, int keycode)
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

void	ft_key_input_rm_key(t_program *game)
{
	int	x;
	int	y;

	x = game->player_position.x;
	y = game->player_position.y;
	if (game->map.array[y][x] == 'C')
		game->map.array[y][x] = '0';
}

void	ft_key_input_quit(t_program *game)
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
		ft_close_map(&game->map);
}

int	ft_key_input(int keycode, t_program *game)
{
	mlx_clear_window(game->mlx, game->window.reference);
	if (keycode == key_esc)
		ft_close_map(&game->map);
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
		game->player.reference, game->player_position.x * 64,
		game->player_position.y * 64);
	return (0);
}