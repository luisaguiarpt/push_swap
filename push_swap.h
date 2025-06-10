/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:46:06 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:04:58 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft/libft.h"
# include "libft/ft_printf/includes/ft_printf.h"

typedef struct s_list
{
	struct s_list	*next;
	int				value;
	int				cost;
	int				i;
}				t_list;

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}				t_stacks;

// Swap operations - swap.c
int		swap(t_list **head);
int		sa(t_stacks *s);
int		sb(t_stacks *s);
int		ss(t_stacks *s);

// Push operations - push.c
int		push(t_list **a, t_list **b);
int		pa(t_stacks *s);
int		pb(t_stacks *s);

// Rotate operations - rotate.c
int		rotate(t_list **head);
int		ra(t_stacks *s);
int		rb(t_stacks *s);
int		rr(t_stacks *s);

// Reverse rotate operations - reverse_rotate.c
int		rev_rotate(t_list **head);
int		rra(t_stacks *s);
int		rrb(t_stacks *s);
int		rrr(t_stacks *s);

// Checker functions - checks.c
int		check_array(char **array);

// Initializer functions - init.c
t_stacks	*init_stacks(void);
void		fill_stack_a(char **char_list, t_stacks *s);

// List initializer functions - list_init.c
void	lstadd_back(t_list **lst, t_list *new);
t_list	*lst_new(int value);

// List utility functions - list_utils.c
void	lst_clear(t_list **lst);
int		lst_size(t_list **head);
t_list	*lst_last(t_list **head);
t_list	*lst_2ndlast(t_list **head);

// Freeing functions - free.c
void	free_all(t_stacks *s);
void	free_array(char ***char_array);
void	free_malloc(t_stacks *s);

// Exit functions - error.c
void	exit_error(void);

#endif
