/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:13 by vhovhann          #+#    #+#             */
/*   Updated: 2023/06/03 13:12:50 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**********************/
/****** INCLUDES ******/
/*********************/
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

/***************************/
/** DEFINES FOR FUNCTIONS **/
/**************************/
# define SA_MSG "sa\n"
# define SB_MSG "sb\n"
# define SS_MSG "ss\n"
# define PA_MSG "pa\n"
# define PB_MSG "pb\n"
# define RA_MSG "ra\n"
# define RB_MSG "rb\n"
# define RR_MSG "rr\n"
# define RRA_MSG "rra\n"
# define RRB_MSG "rrb\n"
# define RRR_MSG "rrr\n"

/*********************************/
/*********** STRUCTURE ***********/
/*********************************/
typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				index;
	int				data;
}t_list;

/********************************************/
/************* PUSH_SWAP_UTILS **************/
/********************************************/
void	ft_free(t_list **stack, char ***str);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);

/**************************************/
/********* FUNCTION FOR ERROR *********/
/**************************************/
void	panic(char *str);

/***************************************/
/******* FUNCTION CHEK ARGUMENTS *******/
/***************************************/
int		*sort_int_arr(int *arr, int len);
void	check_valid_av(char *str);
void	chek_duplicate(char **s);
void	chek_lenght(char *s);
void	chek_sort(char **s);
char	**pars_1(char **av);
int		*intcpy(char **s);

/****************************************************************/
/********************** FUNCTIONS FOR LISTS *********************/
/****************************************************************/
t_list	*fill_nodes(int *arr, char **str, t_list *list, int len);
t_list	*malloc_list(t_list *list, int data, int index);
t_list	*push_back(t_list *list, int data, int index);

/*********************************************/
/************* FUNCTIONS SA_SB_SS ************/
/*********************************************/
void	ss(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack, int is_a);

/********************************************/
/************* FUNCTIONS RA_RB_RR *************/
/********************************************/
void	rr(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack, int is_a);

/**************************************/
/********** FUNCTIONS PA_PB ***********/
/**************************************/
void	push_a(t_list **b, t_list **a);
void	push_b(t_list **a, t_list **b);

/**********************************************/
/************ FUNCTIONS RRA_RRB_RRR ***********/
/**********************************************/
void	revers_rotate(t_list **stack, int is_a);
void	rrr(t_list **stack_a, t_list **stack_b);

/*****************************************************/
/************** FUNCTIONS FOR SORTINGS ***************/
/*****************************************************/
void	butterfly(t_list **stack_a, t_list **stack_b);
void	param_5(t_list **stack_a, t_list **stack_b);
void	param_3(t_list **stack_a);
int		finde_index(t_list **stack_a, int size, int index);
int		counter(int sz);

#endif