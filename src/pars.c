/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:47:33 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/03 18:55:57 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**pars_1(char **av)
{
	int		i;
	char	*str;
	char	**arr;

	i = 1;
	str = NULL;
	while (av && av[i])
	{
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	arr = ft_split(str, ' ');
	free(str);
	return (arr);
}

void	chek_lenght(char *s)
{
	long	i;
	int		j;

	j = 0;
	while (s && s[j] != '\0')
	{
		if (s[j] == '-' || s[j] == '+')
			j++;
		while (s[j] != '\0' && s[j] == '0')
			j++;
		if (ft_strlen(&s[j]) <= 10)
		{
			i = ft_atoi(s);
			if (i > 2147483647 || i < -2147483648)
				panic("Error\n");
			else
				return ;
		}
		else
			panic("Error\n");
	}
}

void	chek_duplicate(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s && s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				panic("Error\n");
			else
				j++;
		}
		i++;
	}
}

void	chek_sort(char **s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
		j++;
	while (ft_atoi(s[i]) < ft_atoi(s[i + 1]) && i < j - 1)
		i++;
	if (j == i + 1)
		exit(EXIT_SUCCESS);
}

int	*intcpy(char **s)
{
	int	i;
	int	len;
	int	j;
	int	*arr;

	len = 0;
	while (s[len] != '\0')
		len++;
	arr = (int *)malloc(sizeof(int) * (len));
	if (!arr)
		panic("Error\n");
	j = 0;
	i = -1;
	while (s[++i] != '\0')
		arr[i] = ft_atoi(&s[i][j]);
	return (arr);
}
