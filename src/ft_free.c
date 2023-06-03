/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:57:12 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/03 13:19:45 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(t_list **stack, char ***str)
{
	int	i;

	i = 0;
	if (stack && (*stack))
	{
		while ((*stack)->next != NULL)
		{
			free((*stack)->prev);
			(*stack) = (*stack)->next;
		}
		free((*stack)->prev);
	}
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
}
