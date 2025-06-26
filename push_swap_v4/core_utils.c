/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:25:01 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:48:13 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_core	*init_core(void)
{
	t_core	*core;

	core = malloc(sizeof(t_core));
	if (!core)
		free_error(core);
	core->a = malloc(sizeof(t_stack));
	if (!core->a)
		free_error(core);
	core->b = malloc(sizeof(t_stack));
	if (!core->b)
		free_error(core);
	*core->a = NULL;
	*core->b = NULL;
	core->size = 0;
	core->print = 1;
	return (core);
}

t_core	*copy_core(t_core *core)
{
	t_core	*copy;

	copy = init_core();
	lst_copy(core->a, copy->a);
	lst_copy(core->b, copy->b);
	copy->size = core->size;
	copy->print = 0;
	copy->sorted_array = NULL;
	return (copy);
}
