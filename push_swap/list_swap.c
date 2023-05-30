/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:18:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/30 15:45:35 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, int is_a)
{
	int	data;
	int	index;

	if (ft_lstsize((*stack)) >= 2)
	{
		data = (*stack)->data;
		index = (*stack)->index;
		(*stack)->data = (*stack)->next->data;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->data = data;
		(*stack)->next->index = index;
		if (is_a == 1)
			write(1, SA_MSG, ft_strlen(SA_MSG));
		else if (is_a == 0)
			write(1, SB_MSG, ft_strlen(SB_MSG));
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 2);
	swap(stack_b, 2);
	write(1, SS_MSG, ft_strlen(SS_MSG));
}
