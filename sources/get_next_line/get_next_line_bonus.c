/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:23:43 by rgomes-c          #+#    #+#             */
/*   Updated: 2022/11/17 11:39:46 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_end_of_file(char **line, char ***str)
{
	if ((***str) != '\0')
		*line = ft_strdup((**str));
	else
		*line = 0;
	free(**str);
	**str = 0;
}

static char	*ft_get_line(int fd, char **str, int char_read, char **buf)
{
	int		i;
	char	*str_temp;
	char	*line;

	i = 0;
	if ((char_read <= 0 && !(*str)) || fd < 0)
	{
		free(*buf);
		return (NULL);
	}
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		line = ft_substr((*str), 0, i);
		str_temp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = str_temp;
	}
	else
		ft_end_of_file(&line, &str);
	free((*buf));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*temp;
	char		*buf;
	int			char_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	char_read = read (fd, buf, BUFFER_SIZE);
	while (char_read > 0)
	{
		buf[char_read] = '\0';
		if (!stash[fd])
			stash[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(stash[fd], buf);
			free(stash[fd]);
			stash[fd] = temp;
		}
		if (check_end_line(stash[fd]))
			break ;
		char_read = read (fd, buf, BUFFER_SIZE);
	}
	return (ft_get_line(fd, &stash[fd], char_read, &buf));
}
