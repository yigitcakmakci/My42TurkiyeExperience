/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:01:16 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/26 19:00:11 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <unistd.h>

static void	push_swap_reverse_rotate(t_stack **reverse_rotate)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	first = *reverse_rotate;
	last = *reverse_rotate;
	while (last->next->next)
		last = last->next;
	before_last = last;
	last = last->next;
	before_last->next = NULL;
	last->next = first;
	*reverse_rotate = last;
}

void	rra(t_stack **a)
{
	if (!a || !*a || !((*a)-> next))
		return ;
	push_swap_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (!b || !*b || !((*b)-> next))
		return ;
	push_swap_reverse_rotate(b);
	write(1, "rrb\n", 4);
}
