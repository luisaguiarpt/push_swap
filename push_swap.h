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
	int				chunk;
	int				cost;
	int				i;
	int				curr_pos;
}				t_list;

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
	int		size;
	int		nbr_chunks;
	int		*chunk_sizes;
}				t_stacks;

// Swap operations - swap.c
int			swap(t_list **head);
int			sa(t_stacks *s);
int			sb(t_stacks *s);
int			ss(t_stacks *s);

// Push operations - push.c
int			push(t_list **a, t_list **b);
int			pa(t_stacks *s);
int			pb(t_stacks *s);

// Rotate operations - rotate.c
int			rotate(t_list **head);
int			ra(t_stacks *s);
int			rb(t_stacks *s);
int			rr(t_stacks *s);

// Reverse rotate operations - reverse_rotate.c
int			rev_rotate(t_list **head);
int			rra(t_stacks *s);
int			rrb(t_stacks *s);
int			rrr(t_stacks *s);

// Checker functions - checks.c
int			check_array(char **array);
int			check_dup(char **array);
void		check_input(char **array);

// Initializer functions - init.c
t_stacks	*init_stacks(void);
void		fill_stack_a(char **char_list, t_stacks *s);

// List initializer functions - list_init.c
t_list		*lst_new(int value);
void		lstadd_back(t_list **lst, t_list *new);
void		lstadd_front(t_list **lst, t_list *new);

// List utility functions - list_utils.c
void		lst_clear(t_list **lst);
int			lst_size(t_list **head);
t_list		*lst_last(t_list **head);
t_list		*lst_2ndlast(t_list **head);
void		lst_copy(t_list **orig, t_list **dest);

// List sort functions - list_sort.c
void		list_swap(t_list **begin, t_list **curr, t_list **prev, int *f);
void		sort_list(t_list **begin, int (*cmp)());

// Index related functions - get_index.c
void		get_index(t_stacks *s);

// Cost related functions - get_cost.c
void		get_cost(t_stacks *s);

// Chunk related funtions - get_chunks.c
int			get_chunk(t_stacks *s, int i);
int			*get_chunk_sizes(t_stacks *s);
int			get_nbr_chunks(t_stacks *s);
int			get_cheapest_chunk(t_stacks *s);
t_list		*get_cheapest_in_chunk(t_list **lst, int chunk);

// Position related functions - get_position.c
void		upd_pos(t_list **lst);

// Sorter related functions - solver.c
int			push_cheapest_b(t_stacks *s, int chunk);
int			push_chunk_b(t_stacks *s, int chunk);

// Freeing functions - free.c
void		free_all(t_stacks *s);
void		free_array(char ***char_array);
void		free_error(t_stacks *s);

// Exit functions - error.c
void		exit_error(void);

#endif
