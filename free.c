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

// Free all the nodes in an array
void	free_array(char ***char_array)
{
	int		i;

	i = 0;
	if (!*char_array)
		return ;
	while (*char_array[i])
	{
		free(*char_array[i]);
		i++;
	}
	free(*char_array);
	*char_array = NULL;
}

// Free stack and list pointers if any of the initial mallocs fail
void	free_malloc(t_stacks *s)
{
	if (!s)
		exit_error();
	if (s->a)
		free(s->a);
	if (s->b)
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
	free(s);
}
