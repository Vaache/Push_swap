/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:18 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/26 22:03:29 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_valid(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '-' || str[i][j] == '+') && j != 0)
				exit(write(2, "Error\n", 6));
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			if (str[i][j] < '0' || str[i][j] > '9')
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
	}
}

int	main(int ac, char **av)
{
	int		len;
	char	**str;
	t_list	*list;

	len = 1;
	list = NULL;
	if (ac <= 2)
		exit(1);
	else
	{
		str = pars_1(av);
		check_valid(str);
		len = -1;
		while (str[++len])
			chek_lenght(str[len]);
		chek_duplicate(str);
		chek_sort(str);
		list = fill_nodes(sort_int_arr(intcpy(str), len), str, list, len);
		while (list)
		{
			printf("data = %d ", list->data);
			printf("index = %d\n", list->index);
			list = list->next;
		}
		
	}
}
