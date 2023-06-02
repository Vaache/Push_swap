/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_revers_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:14:22 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/02 16:26:08 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revers_rotate(t_list **stack, int is_a)
{
	t_list	*tmp;
	t_list	*ptr;

	tmp = (*stack);
	if (ft_lstsize(*stack) >= 1)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (*stack);
		(*stack) = tmp;
		ptr = (*stack);
		while (ptr->next->data != tmp->data)
			ptr = ptr->next;
		ptr->next = NULL;
		(*stack)->prev = NULL;
		if (is_a == 1)
			write(1, RRA_MSG, ft_strlen(RRA_MSG));
		if (is_a == 0)
			write(1, RRB_MSG, ft_strlen(RRB_MSG));
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	revers_rotate(stack_a, 2);
	revers_rotate(stack_b, 2);
	write(1, RRR_MSG, ft_strlen(RRR_MSG));
}
