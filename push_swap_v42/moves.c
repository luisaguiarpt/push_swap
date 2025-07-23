/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:00:06 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/23 19:00:08 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_moves(t_stack **head);

void	upd_moves(t_core *core)
{
	calc_moves(core->a);
	calc_moves(core->b);
}

static void	calc_moves(t_stack **head)
{
	t_stack	*lst;
	int		median;
	int		size;
	int		i;

	lst = *head;
	size = lst_size(head);
	median = size / 2;
	i = 0;
	while (lst)
	{
		if (i <= median)
			lst->moves = i;
		else
			lst->moves = - (size - i);
		i++;
		lst = lst->next;
	}
}
