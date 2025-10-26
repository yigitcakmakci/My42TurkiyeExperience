/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:01:14 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/25 23:23:11 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <unistd.h>
#include <stdio.h>

void	push_swap_rotate(t_stack **rotate)
{
	t_stack	*first;
	t_stack	*last;

	if (!rotate || !*rotate || !((*rotate)-> next))
		return ;
	first = *rotate;
	*rotate = first -> next;
	first -> next = NULL;
	last = *rotate;
	while (last -> next)
		last = last -> next;
	last -> next = first;
}

void	ra(t_stack **a)
{
	push_swap_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	push_swap_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	push_swap_rotate(a);
	push_swap_rotate(b);
	write(1, "rb\n", 3);
}
