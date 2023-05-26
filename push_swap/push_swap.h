/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:13 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/26 21:33:06 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				index;
	int				data;
}t_list;

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	**ft_split(const char *s, char c);
char	**pars_1(char **av);
void	chek_lenght(char *s);
void	chek_duplicate(char **s);
void	chek_sort(char **s);
long	ft_atoi(const char *str);
int		*intcpy(char **s);
int		*sort_int_arr(int *arr, int len);
t_list	*malloc_list(t_list *list, int data, int index);
t_list	*push_back(t_list *list, int data, int index);
t_list	*fill_nodes(int *arr, char **str, t_list *list, int len);

#endif