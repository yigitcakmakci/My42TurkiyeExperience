/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:49:41 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/23 11:34:14 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap_lib.h"
#include <stdlib.h>

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

char	**add_array(char **to, char **from)
{
	int	last_index;
	int	i;

	last_index = array_len(to);
	i = 0;
	while (from[i])
	{
		to[last_index + i] = ft_strdup(from[i]);
		i++;
	}
	to[last_index + i] = NULL;
	return (to);
}

int	real_len(int argc, char **argv)
{
	char	**size_referance;
	int		real_len;
	int		i;
	int		j;

	i = 1;
	real_len = 0;
	while (i < argc)
	{
		size_referance = ft_split(argv[i], ' ');
		j = 0;
		while (size_referance[j])
		{
			real_len++;
			j++;
		}
		free_split(size_referance);
		i++;
	}
	return (real_len);
}

char	**set_tmp(int argc, char **argv)
{
	char	**tmp;
	int		len;
	int		i;
	char	**split;

	len = real_len(argc, argv);
	tmp = malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = NULL;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		tmp = add_array(tmp, split);
		free_split(split);
		i++;
	}
	tmp[len] = NULL;
	return (tmp);
}
