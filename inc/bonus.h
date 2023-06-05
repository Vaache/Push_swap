/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:00:53 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/05 12:27:48 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "push_swap.h"
# include "get_next_line_bonus.h"
# include <stdio.h>

void	chek_functions(char	*str, t_list *a, t_list *b, int *flag);
void	read_steps(t_list *a, t_list *b);
int		ft_strcmp(char *s1, char *s2);
void	chek_sort_list(t_list *a);


#endif