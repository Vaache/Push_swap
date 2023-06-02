/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:46:27 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/02 17:55:45 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	finde_index_b(t_list **stack, int size)
// {
// 	t_list	*tmp;
// 	int		index;
// 	int		i;

// 	i = 0;
// 	index = ft_lstsize((*stack)) - 1;
// 	tmp = (*stack);
// 	while (i <= size / 2)
// 	{
// 		if (tmp->index == index)
// 			return (1);
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return(0);
// }

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		i;
	t_list	*tmp;
	
	while (ft_lstsize((*stack_b)) > 0)
	{
		tmp = (*stack_b);
		size = ft_lstsize((*stack_b)) - 1;
		while (i <= ft_lstsize((*stack_b)) / 2)
		{
			if (tmp->index == size)
				break ;
			else
			{
				i++;
				tmp = tmp->next;
			}
		}
		if (i < ft_lstsize((*stack_b)) / 2)
			while ((*stack_b)->index != size)
				rotate(stack_b, 0);
		else
				while((*stack_b)->index != size)
					revers_rotate(stack_b, 0);
		push_a(stack_a, stack_b);
		i = 0;
		
	}
}

void	butterfly(t_list **stack_a, t_list **stack_b)
{
	int	value;
	int	n;

	value = 0;
	while ((*stack_a) != NULL)
	{
		n = counter(ft_lstsize((*stack_a)) - 1);
		if ((*stack_a)->index <= value)
		{
			push_b(stack_b, stack_a);
			rotate(stack_b, 0);
			value++;
		}
		else if ((*stack_a)->index <= value + n)
		{
			push_b(stack_b, stack_a);
			value++;
		}
		else
			rotate(stack_a, 1);
	}
	sort_list(stack_a, stack_b);
}
