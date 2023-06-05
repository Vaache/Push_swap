/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:33:36 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/05 10:13:02 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, int is_a)
{
	t_list	*first;
	t_list	*end_prev;

	if (ft_lstsize((*stack)) > 1)
	{
		first = (*stack);
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		first->next = NULL;
		end_prev = (*stack);
		while (end_prev->next != NULL)
			end_prev = end_prev->next;
		end_prev->next = first;
		first->prev = end_prev;
		if (is_a == 1)
			write(1, RA_MSG, ft_strlen(RA_MSG));
		else if (is_a == 0)
			write(1, RB_MSG, ft_strlen(RB_MSG));
	}
}

void	rr(t_list **stack_a, t_list **stack_b, int is_rr)
{
	rotate(stack_b, 2);
	rotate(stack_a, 2);
	if (is_rr == 1)
		write(1, RR_MSG, ft_strlen(RR_MSG));
}
