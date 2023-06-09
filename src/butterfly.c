/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:46:27 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/05 10:13:35 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		i;
	t_list	*tmp;

	while (ft_lstsize((*stack_b)) > 0)
	{
		tmp = (*stack_b);
		size = ft_lstsize((*stack_b)) - 1;
		i = 0;
		while (i <= ft_lstsize((*stack_b)) / 2)
		{
			if (tmp->index == size)
				break ;
			i++;
			tmp = tmp->next;
		}
		if (i <= ft_lstsize((*stack_b)) / 2)
			while ((*stack_b)->index != size)
				rotate(stack_b, 0);
		else
			while ((*stack_b)->index != size)
				revers_rotate(stack_b, 0);
		push_a(stack_a, stack_b, 1);
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
			push_b(stack_b, stack_a, 1);
			rotate(stack_b, 0);
			value++;
		}
		else if ((*stack_a)->index <= value + n)
		{
			push_b(stack_b, stack_a, 1);
			value++;
		}
		else
			rotate(stack_a, 1);
	}
	sort_list(stack_a, stack_b);
}
