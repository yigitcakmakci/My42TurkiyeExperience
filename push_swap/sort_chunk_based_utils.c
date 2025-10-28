/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_based_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:36:09 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/26 17:38:59 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	calculate_best_pos(int current_cost, int cost, int pos)
{
	int	best_pos;

	best_pos = -1;
	if (current_cost < cost)
	{
		cost = current_cost;
		best_pos = pos;
	}
	return (best_pos);
}

int	find_pos_a(t_stack *a, int min_index, int max_index, int len)
{
	int	pos;
	int	best_pos;
	int	cost;
	int	current_cost;

	cost = 2147483647;
	pos = 0;
	while (a)
	{
		if (a->index >= min_index && a->index < max_index)
		{
			if (pos <= len / 2)
				current_cost = pos;
			else
				current_cost = len - pos;
			best_pos = calculate_best_pos(current_cost, cost, pos);
		}
		a = a-> next;
		pos++;
	}
	return (best_pos);
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

void	move_stack_a(int pos, int len, t_stack **a)
{
	if (pos <= len / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < len)
		{
			rra(a);
			pos++;
		}
	}
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
