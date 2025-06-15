/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:39:10 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:43:07 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free stack and list pointers if in case of error 
void	free_error(t_stacks *s)
{
	if (!s)
		exit_error();
	if (s->a)
		lst_clear(s->a);
	if (s->b)
		lst_clear(s->b);
	free(s->a);
	free(s->b);
	free(s);
	exit_error();
}

// Free everything to exit
void	free_all(t_stacks *s)
{
	if (s->a)
		lst_clear(s->a);
	if (s->b)
		lst_clear(s->b);
	free(s->a);
	free(s->b);
	free(s->chunk_sizes);
	free(s);
}
