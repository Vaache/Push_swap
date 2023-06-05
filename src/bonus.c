/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:22:21 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/05 18:38:55 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	check_valid_b_av(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] == ' ' && str[i][j] != '\0')
			j++;
		if (str[i][j] == '\0')
			panic("Error\n");
		i++;
	}
}

void	check_valid_b(char **str)
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
	a = fill_nodes(sort_int_arr(intcpy(str), len), str, a, len);
	read_steps(a, b);
	chek_sort_list(a);
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
		if (av[1][0] == '\0')
			panic("Error\n");
	if (ac >= 2)
	{
		check_valid_b_av(av);
		str = pars_1(av);
		check_valid_b(str);
		len = -1;
		norm(str, a, b, len);
	}
	return (0);
}
