/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:57:12 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/05 19:42:54 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **stack, char ***str)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
	if (stack && (*stack))
	{
		while (temp)
		{
			temp = temp->next;
			free(*stack);
			*stack = temp;
		}
		free((*stack));
	}
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
}
