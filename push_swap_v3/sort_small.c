/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:48:13 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 18:04:31 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_core *core)
{
	t_stack	*high;
	t_stack	*low;
	t_stack	**head;

	head = core->a;
	high = get_max_index(core->a);
	low = get_min_index(core->a);
	if (*head == high)
		ra(core);
	else if ((*head)->next == high)
		rra(core);
	if (*head != low)
		sa(core);
}

void	sort_5(t_core *core)
{
	if (is_sorted(core->a))
		return ;
	pb(core);
	pb(core);
	sort_3(core);

}
