/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:13:38 by vhovhann          #+#    #+#             */
/*   Updated: 2023/05/30 13:13:49 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counter(int count)
{
	int	root;
	int	log;
	int	step;

	log = 1;
	root = 1;
	step = 0;
	while (root * root <= count)
	{
		root++;
		step++;
	}
	while (log * 2 <= count)
	{
		log *= 2;
		step++;
	}
	return (step);
}
