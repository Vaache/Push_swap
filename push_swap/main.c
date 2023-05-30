/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:18 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/30 22:11:07 by vhovhann         ###   ########.fr       */
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
				panic("Error\n");
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			if (str[i][j] < '0' || str[i][j] > '9')
				panic("Error\n");
			j++;
		}
	}
}

int	main(int ac, char **av)
{
	int		len;
	char	**str;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac <= 2)
	{
		if ((size_t)ft_atoi(av[1]) > (size_t)2147483647 \
		|| (size_t)ft_atoi(av[1]) < (size_t)(-2147483648))
			panic("Error\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		str = pars_1(av);
		check_valid(str);
		len = -1;
		while (str[++len])
			chek_lenght(str[len]);
		chek_duplicate(str);
		chek_sort(str);
		a = fill_nodes(sort_int_arr(intcpy(str), len), str, a, len);
		len = ft_lstsize(a);
		if (len <= 3)
			param_3(&a);
		if (len >= 4 && len <= 12)
			param_5(&a, &b);
	}
}
