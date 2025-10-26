/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:48:47 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/25 22:53:54 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_lib.h"
#include <unistd.h>

static	void	pong_process(t_stack **stack_a, t_stack **stack_b, int byte)
{
	int	stack_l;
	int	i;

	stack_l = stack_len(*stack_b);
	i = 0;
	while (i < stack_l)
	{
		if (((*stack_b)-> index >> byte) & 1)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		i++;
	}
}

static	void	ping_process(t_stack **stack_a, t_stack **stack_b, int byte)
{
	int	stack_l;
	int	i;

	stack_l = stack_len(*stack_a);
	i = 0;
	while (i < stack_l)
	{
		if (((*stack_a)-> index >> byte) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
}

void	radix_mechanism(int max_byte, t_stack **stack_a, t_stack **stack_b)
{
	int	byte;

	byte = 0;
	while (byte < max_byte)
	{
		ping_process(stack_a, stack_b, byte);
		byte++;
		if (byte == max_byte)
			break ;
		pong_process(stack_a, stack_b, byte);
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

void	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		max_index;
	int		max_byte;
	t_stack	*tmp;

	tmp = *stack_a;
	max_index = 0;
	while (tmp)
	{
		if ((tmp -> index) > max_index)
			max_index = tmp -> index;
		tmp = tmp -> next;
	}
	max_byte = 0;
	while (max_index >> max_byte != 0)
		max_byte++;
	radix_mechanism(max_byte, stack_a, stack_b);
}
