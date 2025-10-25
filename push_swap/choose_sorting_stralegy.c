/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sorting_stralegy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 19:39:13 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/25 22:11:22 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	choose_stralegy(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*a)-> value > (*a)->next-> value)
			sa(a);
	}
	else if (len == 3)
		sort_hard_coded(a);
	else if (len <= 5)
		sort_selection(a, b);
	else if (len <= 100)
		sort_chunk_based(a, b);
	else
		sort_radix(a, b);
}
