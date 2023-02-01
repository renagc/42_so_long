/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:37:16 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/01 21:46:49 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close(t_program *game)
{
	ft_free_img_and_win(game);
	ft_free_close_map(&game->mlx, &game->map);
	return (0);
}

t_window	ft_new_window(t_program *game, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(game->mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	mlx_hook(window.reference, 17, 1L << 0, ft_close, game);
	return (window);
}
