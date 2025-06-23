/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:31:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 12:39:25 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_core *core)
{
	int		i;
	int		size;
	int		*array;
	t_stack	*lst;

	lst = *core->a;
	size = lst_size(core->a);
	array = core->sorted_array;
	while (lst)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == lst->value)
				lst->index = i;
			i++;
		}
		lst = lst->next;
	}
}
