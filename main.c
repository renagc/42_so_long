/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:45:11 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/01 21:45:32 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_ac_check(int n)
{
	ft_printf("Error\n");
	if (n == 1)
		ft_printf("You must choose a file\n");
	else if (n > 2)
		ft_printf("Program as more than 2 arguments\n");
	exit (0);
}

static void	ft_check_ext_and_file(char *str)
{
	int		i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], ".ber", 4) != 0)
	{
		ft_printf("Error\nMap must have .ber extension\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_program	game;
	int			x;
	int			y;

	if (ac != 2)
		ft_ac_check(ac);
	ft_check_ext_and_file(av[1]);
	game.mlx = mlx_init();
	game.map = ft_open_map(&game.mlx, av[1]);
	game.map.chars = ft_get_char_img(&game);
	x = game.map.size.x * 64;
	y = game.map.size.y * 64;
	game.window = ft_new_window(&game, x, y, "so_long");
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
