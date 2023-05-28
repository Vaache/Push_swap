/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:33:36 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/27 19:36:32 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, int is_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*end_prev;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = (*stack);
	second = (*stack)->next;
	while ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	end_prev = (*stack);
	end_prev->next = first;
	first->prev = end_prev;
	first->next = NULL;
	second->prev = NULL;
	(*stack) = second;
	if (is_a == 1)
		write(1, RA_MSG, ft_strlen(RA_MSG));
	else if (is_a == 0)
		write(1, RB_MSG, ft_strlen(RB_MSG));
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_b, 2);
	rotate(stack_a, 2);
	write(1, RR_MSG, ft_strlen(RR_MSG));
}
