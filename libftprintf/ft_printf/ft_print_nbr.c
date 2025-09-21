/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:19:33 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/07/20 19:16:04 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_nbr(int n)
{
	char	buf[12];
	int		i;
	int		len;
	long	nb;

	i = 0;
	len = 0;
	nb = n;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		buf[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (i--)
		len += write(1, &buf[i], 1);
	return (len);
}
