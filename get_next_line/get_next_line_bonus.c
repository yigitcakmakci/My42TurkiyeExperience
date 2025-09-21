/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:27:50 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/09/18 17:19:39 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

static char	*move_buffer(char *buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	return (new_buffer);
}

static char	*get_lines(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_substr(buffer, 0, i));
}

static char	*fill_buffer(int fd, char *buffer)
{
	char	*tmp;
	int		bytes;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			free(buffer);
			return (NULL);
		}
		tmp[bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*res;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = fill_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	res = get_lines(buffer[fd]);
	buffer[fd] = move_buffer(buffer[fd]);
	return (res);
}
