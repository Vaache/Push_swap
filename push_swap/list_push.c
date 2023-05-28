/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:49:50 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/27 19:59:58 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*node;

	if ((*b) == NULL)
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
		node->next = (*a);
		(*a)->prev = node;
		node->prev = NULL;
		(*b) = (*b)->next;
		(*b)->prev = NULL;
	}
	write(1, PA_MSG, ft_strlen(PA_MSG));
}

void	push_b(t_list **b, t_list **a)
{
	t_list	*node;

	if ((*a) == NULL)
		return ;
	if (!(*b))
	{
		(*b) = (*a);
		(*a) = (*a)->next;
		(*a)->prev = NULL;
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
	else
	{
		node = (*a);
		node->next = (*b);
		node->prev = NULL;
		(*b)->prev = node;
		(*a) = (*a)->next;
		(*a)->prev = NULL;
	}
	write(1, PB_MSG, ft_strlen(PB_MSG));
}
