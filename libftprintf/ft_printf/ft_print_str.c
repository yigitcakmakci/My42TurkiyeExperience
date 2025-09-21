/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:58:44 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/07/20 18:51:01 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_str(char *c)
{
	int		i;
	int		count;

	if (c == NULL)
		return (write(1, "(null)", 6));
	count = 0;
	i = 0;
	while (c[i])
	{
		if (write(1, &c[i], 1) == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}
