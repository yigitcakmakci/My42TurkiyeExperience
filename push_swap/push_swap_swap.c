/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:01:11 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/07 20:18:11 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <unistd.h>

void	push_swap_swap(t_stack **swap)
{
	int	hold_number;

	if (swap == NULL || *swap == NULL)
	{
		return ;
	}
	hold_number = (*swap)-> value;
	(*swap)-> value = (*swap)-> next -> value;
	(*swap)-> next -> value = hold_number;
}

void	sa(t_stack **swap)
{
	push_swap_swap(swap);
	write(1, "sa\n", 3);
}

void	sb(t_stack **swap)
{
	push_swap_swap(swap);
	write(1, "sb\n", 3);
}
