/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:45:11 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/01/30 12:30:06 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_ac_check(int n)
{
	if (n == 1)
		perror("You must choose a map");
	else if (n > 2)
		perror("Program as more than 2 arguments");
	exit (0);
}

int	main(int ac, char **av)
{
	t_program	game;
	int			x;
	int			y;

	if (ac != 2)
		ft_ac_check(ac);
	game.mlx = mlx_init();
	game.map = ft_open_map(av[1]);
	game.map.chars = ft_get_char_img(&game);
	x = game.map.size.x * 64;
	y = game.map.size.y * 64;
	game.window = ft_new_window(game.mlx, x, y, "so_long");
	game.player = ft_new_xpm_img(game.mlx, "textures/player.xpm");
	game.player_position = ft_get_player_position(&game.map);
	ft_draw_background(&game);
	mlx_put_image_to_window(game.mlx, game.window.reference,
		game.player.reference, game.player_position.x * 64,
		game.player_position.y * 64);
	game.map.moves = 0;
	mlx_key_hook(game.window.reference, *ft_key_input, &game);
	mlx_loop(game.mlx);
}