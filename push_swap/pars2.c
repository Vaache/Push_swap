/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:28:37 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/27 13:26:05 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_int_arr(int *arr, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

t_list	*malloc_list(t_list *list, int data, int index)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->data = data;
	tmp->index = index;
	list = tmp;
	return (list);
}

t_list	*push_back(t_list *list, int data, int index)
{
	t_list	*tmp;
	t_list	*ptr;

	tmp = NULL;
	if (NULL == list)
	{
		list = malloc_list(list, data, index);
		return (list);
	}
	tmp = malloc_list(tmp, data, index);
	ptr = list;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->prev = ptr;
	return (list);
}
