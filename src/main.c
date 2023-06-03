/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:18 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/03 11:06:18 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_valid_av(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			break ;
		i++;
	}
	if (str[i] == '\0')
		panic("Error\n");
}

void	check_valid(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str && str[++i])
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

static void	norm(char **str, t_list *a, t_list *b, int len)
{
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
	if (len > 12)
		butterfly(&a, &b);
	ft_free(&a, &str);
}

int	main(int ac, char **av)
{
	int		len;
	char	**str;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		exit(EXIT_SUCCESS);
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			panic("Error\n");
		check_valid_av(av[1]);
	}
	if (ac >= 2)
	{
		str = pars_1(av);
		check_valid(str);
		len = -1;
		norm(str, a, b, len);
	}
}
