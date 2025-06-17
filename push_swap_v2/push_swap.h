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

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				chunk;
	int				i;
	int				cost;
}				t_stack;

typedef struct s_core
{
	t_stack	**a;
	t_stack	**b;
	int		size;
	int		nbr_chunks;
	int		*chunk_sizes;
	int		print;
	int		tmp_cost;
}				t_core;

// TEMPORARY FUNCTIONS
void	prt_lst(t_stack **lst);
void	prt_core(t_core *core);

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

// Stacks functions - stack_utils.c
t_core		*init_core(void);
t_core		*copy_core(t_core *core);
void		fill_stack_a(char **char_arr, t_core *core);

// List functions - list.c
t_stack		*lst_new(int value);
void		lstadd_back(t_stack **lst, t_stack *new);
void		lstadd_front(t_stack **lst, t_stack *new);
t_stack		*lst_find(t_stack **head, int value, char attr);

// List utility functions - list_utils.c
void		lst_clear(t_stack **lst);
int			lst_size(t_stack **head);
t_stack		*lst_last(t_stack **head);
t_stack		*lst_2ndlast(t_stack **head);
void		lst_copy(t_stack **orig, t_stack **dest);

// Chunk related functions - chunk_utils.c
int			*chunk_size_array(t_core *core);
t_stack		*cheapest_in_chunk(t_stack **lst, int chunk);
int			chunks_in_stack(t_core *core);
int			ischunk_in_stack(t_stack **head, int chunk);

// Index and chunk related functions - attr_utils.c
void		assign_attr(t_core *core);
t_stack		*get_max_index(t_stack **head);

// Cost related functions - cost_utils.c
void		upd_cost(t_core *core);
void		calc_cost(t_stack **lst);
int			get_cost(t_stack **lst, int index);

// Sorting related functions - sort.c
void		sort(t_core *core);
int			push_chunk_b(t_core *core, int chunk);
int			move_to_position(t_core *core, int chunk);
void		rot_max_to_top(t_core *core);
void		push_all_a(t_core *core);

// Sorting utilities - sort_utils.c
int			cheapest_chunk(t_core *core);
t_stack		*get_target(t_stack **b, t_stack *ref);

// Freeing functions - free.c
void		free_all(t_core *s);
void		free_error(t_core *s);

// Exit functions - error.c
void		exit_error(void);

#endif
