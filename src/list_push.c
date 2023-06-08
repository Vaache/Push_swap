/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:49:50 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/05 19:42:13 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b, int is_pa)
{
	t_list	*node;

	if (ft_lstsize(*b) == 0)
		return ;
	if (!(*a))
	{
		(*a) = (*b);
		(*b) = (*b)->next;
		(*b)->prev = NULL;
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
	else
	{
		node = (*b);
		(*b) = (*b)->next;
		if (*b != NULL)
			(*b)->prev = NULL;
		node->next = (*a);
		(*a)->prev = node;
		(*a) = node;
	}
	if (is_pa == 1)
		write(1, PA_MSG, ft_strlen(PA_MSG));
}

void	push_b(t_list **b, t_list **a, int is_pb)
{
	t_list	*node;

	if (ft_lstsize(*a) == 0)
		return ;
	if (!(*b))
	{
		(*b) = (*a);
		if ((*a)->next)
			(*a) = (*a)->next;
		(*a)->prev = NULL;
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	else
	{
		node = (*a);
		(*a) = (*a)->next;
		if (*a != NULL)
			(*a)->prev = NULL;
		node->next = (*b);
		(*b)->prev = node;
		(*b) = node;
	}
	if (is_pb == 1)
		write(1, PB_MSG, ft_strlen(PB_MSG));
}
