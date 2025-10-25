/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_based.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:30:53 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/25 22:08:57 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

static void	optimized_push_b(t_stack **a, t_stack **b, int chunk_size)
{
	int	chunk_index;
	int	counter;
	int	midpoint;

	chunk_index = 1;
	while (*a)
	{
		counter = 0;
		while (counter < chunk_size && *a)
		{
			midpoint = ((chunk_size * chunk_index) - chunk_size / 2);
			if ((*a)->index < (chunk_size * chunk_index)
				&& (*a)-> index >= (chunk_size * (chunk_index - 1)))
			{
				pb(a, b);
				counter++;
				if ((*b)-> index < midpoint)
					rb(b);
			}
			else
				ra(a);
		}
		chunk_index++;
	}
}

static void	largest_push(t_stack **a, t_stack **b)
{
	int	max_index;
	int	len;
	int	pos;

	max_index = stack_len(*b) - 1;
	while (*b)
	{
		len = stack_len(*b);
		pos = find_pos_b(*b, max_index);
		move_stack_b(pos, len, b);
		pa(a, b);
		max_index--;
	}
}

void	sort_chunk_based(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	len;

	len = stack_len(*a);
	if (len <= 100)
		chunk_size = 20;
	else
		chunk_size = len / 9;
	optimized_push_b(a, b, chunk_size);
	largest_push(a, b);
}
