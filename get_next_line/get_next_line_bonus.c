/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:27:50 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/13 14:14:54 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

static char	*move_buffer(char *buffer, int len)
{
	char	*new_buffer;

	if (!buffer || len == 0 || !buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_substr(buffer, len, ft_strlen(buffer) - len);
	free(buffer);
	return (new_buffer);
}

static t_lineandlen	*get_lines(char *buffer)
{
	int				i;
	t_lineandlen	*res;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	res = malloc(sizeof(t_lineandlen));
	if (!res)
		return (NULL);
	res->line = ft_substr(buffer, 0, i);
	res->len = i;
	return (res);
}

static char	*fill_buffer(int fd, char *buffer)
{
	char	*tmp;
	int		bytes;

	if (!buffer)
		buffer = ft_strdup("");
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes > 0)
		{
			tmp[bytes] = '\0';
			buffer = ft_strjoin(buffer, tmp);
		}
	}
	free(tmp);
	if (bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[1024];
	t_lineandlen	*tmp;
	char			*res;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = fill_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	tmp = get_lines(buffer[fd]);
	if (!tmp)
	{
		if (buffer[fd] && buffer[fd][0])
			res = ft_strdup(buffer[fd]);
		else
			res = NULL;
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (res);
	}
	buffer[fd] = move_buffer(buffer[fd], tmp->len);
	res = ft_strdup(tmp->line);
	free(tmp->line);
	free(tmp);
	return (res);
}
