/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:34:41 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/05 12:45:12 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bonus.h"

int    ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	chek_functions(char	*str, t_list *a, t_list *b, int *flag)
{
	if (ft_strcmp(str, SA_MSG) == 0)
		swap(&a, 2);
	else if (ft_strcmp(str, SB_MSG) == 0)
		swap(&b, 2);
	else if (ft_strcmp(str, SS_MSG) == 0)
		ss(&a, &b, 0);
	else if (ft_strcmp(str, PA_MSG) == 0)
		push_a(&a, &b, 0);
	else if (ft_strcmp(str, PB_MSG) == 0)
		push_b(&b, &a, 0);
	else if (ft_strcmp(str, RA_MSG) == 0)
		rotate(&a, 2);
	else if (ft_strcmp(str, RB_MSG) == 0)
		rotate(&b, 2);
	else if (ft_strcmp(str, RR_MSG) == 0)
		rr(&a, &b, 2);
	else if (ft_strcmp(str, RRA_MSG) == 0)
		revers_rotate(&a, 2);
	else if (ft_strcmp(str, RRB_MSG) == 0)
		revers_rotate(&b, 2);
	else if (ft_strcmp(str, RRR_MSG) == 0)
		rrr(&a, &b, 0);
	else
		*flag = 1;	
}

void	read_steps(t_list *a, t_list *b)
{
	int		flag;
	char	*read;

	flag = 0;
	while (1)
	{
		read = get_next_line(0);
		if (read == '\0')
			break ;
		chek_functions(read, a, b, &flag);
		free(read);
	}
	if (flag == 1)
		panic("KO\n");
}

void	chek_sort_list(t_list *a)
{
	while (a->next != NULL)
	{
		if (a->index + 1 != a->next->index)
			panic("Error\n");
		a = a->next;
	}
	write(1, "OK\n", 3);
}