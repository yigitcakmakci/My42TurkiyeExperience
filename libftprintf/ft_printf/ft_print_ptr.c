/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:10:20 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/07/20 19:02:22 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_ptr(void *n)
{
	unsigned long	ptr;
	char			*hex;
	char			buffer[16];
	int				i;
	int				hold_size;

	if (n == 0)
		return (write(1, "(nil)", 5));
	ptr = (unsigned long)n;
	hex = "0123456789abcdef";
	i = 0;
	hold_size = write(1, "0x", 2);
	while (ptr)
	{
		buffer[i++] = hex[ptr % 16];
		ptr /= 16;
	}
	hold_size += i;
	while (i--)
	{
		if (write(1, &buffer[i], 1) == -1)
			return (-1);
	}
	return (hold_size);
}
