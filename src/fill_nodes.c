/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:32:17 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/02 15:42:46 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_nodes(int *arr, char **str, t_list *list, int len)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 0;
	j = 0;
	tmp = list;
	while (j < len)
	{
		if (str[i] && arr[j] == ft_atoi(str[i]))
		{
			tmp = push_back(tmp, ft_atoi(str[i]), j);
			i++;
			j = 0;
		}
		else
			j++;
	}
	list = tmp;
	free(arr);
	return (list);
}
