/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:01:49 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/02/01 21:56:14 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// ------------------------------- INCLUDES --------------------------------- //

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "sources/ft_printf/ft_printf.h"
# include "sources/libft/libft.h"
# include "sources/libft_ext/libft_ext.h"
# include "sources/get_next_line/get_next_line.h"
# include "sources/get_next_line/get_next_line_bonus.h"

// -------------------------------- MACROS ---------------------------------- //

enum e_keys{
	key_up = 119,
	key_down = 115,
	key_right = 100,
	key_left = 97,
	key_esc = 65307
};

// ------------------------------- STRUCTS ---------------------------------- //

typedef struct s_vector
{
	int	x;
	int	y;
}t_vector;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}t_window;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
}t_image;

typedef struct s_symbol
{
	int	wall;
	int	floor;
	int	exit;
	int	player;
	int	key;
}t_symbol;

typedef struct s_chars
{
	t_image	wall;
	t_image	floor;
	t_image	exit;
	t_image	player;
	t_image	key;
}t_chars;

typedef struct s_map
{
	char		**array;
	t_vector	size;
	t_chars		chars;
	int			moves;
}t_map;

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_image		player;
	t_vector	player_position;
	t_map		map;
}t_program;

// -----------------------------  FUNCTIONS --------------------------------- //

//	map_check_rules.c
t_map		ft_open_map(void **mlx, char *path);

//	draw.c
t_chars		ft_get_char_img(t_program *game);
void		ft_draw_background(t_program *game);
void		ft_free_img_and_win(t_program *game);

//	gen_window.c
t_window	ft_new_window(t_program *game, int widht, int height, char *name);

//	gen_image.c
t_image		ft_new_xpm_img(void *mlx, char *path);

// map_utils.c
t_vector	ft_get_player_position(t_map *map);
void		ft_free_close_map(void **mlx, t_map *map);

//	gen_hooks.c
int			ft_key_input(int key, t_program *game);

//	map_check_path.c
void		ft_check_map_path(void **mlx, t_map *map);

#endif