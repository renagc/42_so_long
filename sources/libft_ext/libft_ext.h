/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ext.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:37:54 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/01/28 19:02:51 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXT_H
# define LIBFT_EXT_H

# include "../libft/libft.h"
# include <stdlib.h>

// ----------------------------- FUNCTIONS ---------------------------------- //

// -> Part 1
int		ft_iscinstr(char *str, char c);
char	**ft_strsdup(char **s1);
void	ft_free_array(char **array);
char	**ft_cp_array(char **array);

#endif