/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:58:37 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/07 18:49:14 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <stdlib.h>

static	void	assign_index(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		index;

	tmp1 = stack;
	while (tmp1)
	{
		index = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp2->value < tmp1->value)
				index++;
			tmp2 = tmp2->next;
		}
		tmp1->index = index;
		tmp1 = tmp1->next;
	}
}

int	*array_init(t_stack *stack)
{
	int	*array;
	int	i;
	int	max_len;

	max_len = stack_len(stack);
	array = malloc(sizeof(int) * max_len);
	if (!array)
		return (NULL);

	i = 0;
	while (stack)
	{
		array[i] = stack -> value;
		stack = stack -> next;
		i++;
	}
	return (array);
}

t_stack	*set_new_node(char **tmp, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node -> value = ft_atoi(tmp[index]);
	new_node -> index = -1;
	new_node -> next = NULL;
	return (new_node);
}

t_stack	*stack_init(char **tmp)
{
	t_stack	*stack;
	t_stack	*new_node;
	t_stack	*last;
	int		i;

	stack = NULL;
	last = NULL;
	i = 0;
	while (tmp[i])
	{
		new_node = set_new_node(tmp, i);
		if (!stack)
		{
			stack = new_node;
			last = new_node;
		}
		else
		{
			last -> next = new_node;
			last = new_node;
		}
		i++;
	}
	assign_index(stack);
	return (stack);
}

int	stack_len(t_stack *stack)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp -> next;
	}
	return (len);
}
