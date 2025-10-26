/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:49:32 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/10/26 16:23:53 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"
#include <unistd.h>
#include <stdlib.h>

static int	*sort_and_return(char **tmp)
{
	t_stack	*a;
	t_stack	*b;
	int		a_len;
	int		*result;

	a = NULL;
	b = NULL;
	a = stack_init(tmp);
	free_split(tmp);
	a_len = stack_len(a);
	choose_stralegy(&a, &b);
	result = array_init(a);
	if (!result)
		return (NULL);
	ft_lstclear(a);
	ft_lstclear(b);
	return (result);
}

int	*push_swap(int argc, char **argv)
{
	char	**tmp;
	int		*result;

	tmp = set_tmp(argc, argv);
	if (argc == 1)
		return (NULL);
	if (!check_argv(tmp))
	{		
		write(1, "Error\n", 7);
		free_split(tmp);
		return (NULL);
	}
	result = sort_and_return(tmp);
	return (result);
}

int main(int argc, char **argv)
{
	push_swap(argc, argv);
	
	/*#include<stdio.h>
	int i = 0;
	int *res = push_swap(argc, argv);
	while (res[i] != '\0')
	{
		printf("%i ", res[i]);
		i++;
	}*/
}
