/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:46:06 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 15:26:46 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft/libft.h"
# include "libft/ft_printf/includes/ft_printf.h"

# define NOARGS	1

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

// Swap operations
int	swap(t_list **head);
int	sa(t_stacks *s);
int	sb(t_stacks *s);
int	ss(t_stacks *s);

// Push operations
int	push(t_list **a, t_list **b);
int	pa(t_stacks *s);
int	pb(t_stacks *s);

// List functions
t_list	*lst_new(int value);
void	lst_delone(t_list **lst);
int		lst_size(t_list **lst);

#endif
