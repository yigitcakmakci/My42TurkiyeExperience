/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_based_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:36:09 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/25 21:17:50 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	move_stack_a(int pos, int len, t_stack **a)
{
    if (pos <= len / 2)
    {
        while (pos > 0)
        {
            ra(a); // ra kullan
            pos--;
        }
    }
    else
    {
        while (pos < len)
        {
            rra(a); // rra kullan
            pos++;
        }
    }
}

int	find_pos_b(t_stack *b, int max_index)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (b->index == max_index)
			return (pos);
		pos++;
		b = b->next;
	}
	return (-1);
}

void	move_stack_b(int pos, int len, t_stack **b)
{
	if (pos <= len / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		while (pos < len)
		{
			rrb(b);
			pos++;
		}
	}
}