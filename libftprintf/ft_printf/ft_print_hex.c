/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:01:30 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/07/20 18:49:49 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_hex(unsigned int n, char x_is_lower)
{
	char	*hex;
	char	buf[8];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (x_is_lower == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		buf[i++] = hex[n % 16];
		n /= 16;
	}
	while (i--)
	{
		if (write(1, &buf[i], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}
