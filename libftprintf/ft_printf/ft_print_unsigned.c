/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:32:32 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/07/20 18:51:10 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_unsigned(unsigned int n)
{
	char	buf[10];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
	{
		if (write(1, &buf[i], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}
