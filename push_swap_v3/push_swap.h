/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:46:06 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 12:37:14 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft/libft.h"
# include "libft/ft_printf/includes/ft_printf.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
	int				moves;
	int				cost;
}				t_stack;

typedef struct s_core
{
	t_stack	**a;
	t_stack	**b;
	int		size;
	int		print;
	int		*sorted_array;
}				t_core;

// TEMPORARY FUNCTIONS
void	prt_lst(t_stack **lst);
void	prt_core(t_core *core);

// Sort initialization - sort_init.c
void		init_stack_a(t_core *core, char **char_arr);

// Main sort - sort.c
void		sort(t_core *core);
void		move_cheapest(t_core *core);

// Sort utilities - sort_utils.c
int			is_sorted(t_stack **head);
int			is_rev_sorted(t_stack **head);
t_stack		*get_target(t_stack **b, t_stack *ref);
t_stack		*get_cheapest(t_core *core);

// Cost - sort_cost.c
void		upd_cost(t_core *core);
t_stack		*get_max_index(t_stack **head);
t_stack		*get_min_index(t_stack **head);

// Moves - moves.c
void		upd_moves(t_core *core);

// Index - index.c
void		assign_index(t_core *core);

// Swap operations - swap.c
int			swap(t_stack **head);
int			sa(t_core *core);
int			sb(t_core *core);
int			ss(t_core *core);

// Push operations - push.c
int			push(t_stack **a, t_stack **b);
int			pa(t_core *core);
int			pb(t_core *core);

// Rotate operations - rotate.c
int			rotate(t_stack **head);
int			ra(t_core *core);
int			rb(t_core *core);
int			rr(t_core *core);

// Reverse rotate operations - reverse_rotate.c
int			rev_rotate(t_stack **head);
int			rra(t_core *core);
int			rrb(t_core *core);
int			rrr(t_core *core);

// Checker functions - checks.c
int			check_array(char **array);
int			check_dup(char **array);
void		check_input(char **array);

// Core functions - core_utils.c
t_core		*init_core(void);
t_core		*copy_core(t_core *core);

// Stack functions - stack.c
t_stack		*lst_new(int value);
void		lstadd_back(t_stack **lst, t_stack *new);
void		lstadd_front(t_stack **lst, t_stack *new);
t_stack		*lst_find(t_stack **head, int value, char attr);

// Stack utility functions - stack_utils.c
void		lst_clear(t_stack **lst);
int			lst_size(t_stack **head);
t_stack		*lst_last(t_stack **head);
t_stack		*lst_2ndlast(t_stack **head);
void		lst_copy(t_stack **orig, t_stack **dest);

// Freeing functions - free.c
void		free_all(t_core *s);
void		free_error(t_core *s);

// Exit functions - error.c
void		exit_error(void);

#endif
