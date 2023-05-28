/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:18:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/27 19:28:00 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, int is_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	third = (*stack)->next->next;
	second->prev = NULL;
	first->next = third;
	third->prev = first;
	second->next = first;
	first->prev = second;
	*stack = second;
	if (is_a == 1)
		write(1, SA_MSG, ft_strlen(SA_MSG));
	else if (is_a == 0)
		write(1, SB_MSG, ft_strlen(SB_MSG));
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 2);
	swap(stack_b, 2);
	write(1, SS_MSG, ft_strlen(SS_MSG));
}
