/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alghorithm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:44:48 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/05 10:18:40 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	param_3(t_list **stack_a)
{
	if (ft_lstsize((*stack_a)) > 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data && \
			(*stack_a)->data > (*stack_a)->next->next->data)
			rotate(stack_a, 1);
		if ((*stack_a)->next->data > (*stack_a)->data && \
			(*stack_a)->next->data > (*stack_a)->next->next->data)
			revers_rotate(stack_a, 1);
	}
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap(stack_a, 1);
}

int	finde_index(t_list **stack_a, int size, int index)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = (*stack_a);
	while (i <= size / 2)
	{
		if (tmp->index == index)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	param_5(t_list **stack_a, t_list **stack_b)
{
	int		n;

	n = 0;
	while (ft_lstsize(*stack_a) >= 3)
	{
		if (finde_index(stack_a, ft_lstsize(*stack_a), n) == 1)
			while ((*stack_a)->index != n)
				rotate(stack_a, 1);
		else
			while ((*stack_a)->index != n)
				revers_rotate(stack_a, 1);
		push_b(stack_b, stack_a, 1);
		n++;
	}
	param_3(stack_a);
	while ((*stack_b) != NULL)
		push_a(stack_a, stack_b, 1);
}
