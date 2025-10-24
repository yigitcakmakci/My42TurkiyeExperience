/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:03:10 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/23 12:09:10 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <stdio.h>

void	push_smallest(int *smallest, t_stack **a, t_stack **b)
{	
	int		counter;
	int		counter_target;

	counter = 0;
	if (stack_len(*a) == 4)
		counter_target = 1;
	else
		counter_target = 2;
	while (counter < counter_target)
	{
		if (smallest[counter] == (*a)-> value)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
}

void	find_smallest(int *smallest, t_stack **a)
{
	t_stack		*tmp;

	tmp = *a;
	smallest[0] = 2147483647;
	while (tmp)
	{
		if (tmp-> value < smallest[0])
		{
			smallest[0] = tmp -> value;
		}
		tmp = tmp-> next;
	}

	smallest[1] = 2147483647;
	tmp = *a;
	while (tmp)
	{
		if (tmp-> value < smallest[1] && tmp-> value != smallest[0])
		{
			smallest[1] = tmp -> value;
		}
		tmp = tmp->next;
	}
}

void	sort_selection(t_stack **a, t_stack **b)
{
	int		smallest[2];

	find_smallest(smallest, a);
	push_smallest(smallest, a, b);
	sort_hard_coded(a);
	if (((*b)-> next != NULL) && ((*b)-> value < (*b)-> next -> value))
		sb(b);
	while (*b)
		pa(a, b);
}
