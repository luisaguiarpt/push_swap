/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:39:10 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 17:37:18 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free stack and list pointers if in case of error 
void	free_error(t_core *core)
{
	if (!core)
		exit_error();
	if (core->a)
		lst_clear(core->a);
	if (core->b)
		lst_clear(core->b);
	free(core->a);
	free(core->b);
	free(core->sorted_array);
	free(core);
	exit_error();
}

// Free everything to exit
void	free_all(t_core *core)
{
	if (core->a)
		lst_clear(core->a);
	if (core->b)
		lst_clear(core->b);
	free(core->a);
	free(core->b);
	free(core->sorted_array);
	free(core);
}
