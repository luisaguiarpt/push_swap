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

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		free_error(stacks);
	stacks->a = malloc(sizeof(t_list));
	if (!stacks->a)
		free_error(stacks);
	stacks->b = malloc(sizeof(t_list));
	if (!stacks->b)
		free_error(stacks);
	*stacks->a = NULL;
	*stacks->b = NULL;
	stacks->chunk_sizes = NULL;
	stacks->nbr_chunks = 0;
	stacks->print = 1;
	return (stacks);
}

t_stacks	*copy_stack(t_stacks *s)
{
	t_stacks	*copy;

	copy = init_stacks();
	lst_copy(s->a, copy->a);
	lst_copy(s->b, copy->b);
	copy->size = s->size;
	copy->nbr_chunks = s->nbr_chunks;
	copy->print = 0;
	return (copy);
}

void	fill_stack_a(char **char_list, t_stacks *s)
{
	int		i;

	i = 0;
	while (char_list[i])
	{
		lstadd_back(s->a, lst_new(ft_atoi(char_list[i])));
		i++;
	}
	s->size = lst_size(s->a);
	get_index_and_chunk(s);
	upd_lst_cost(s);
	s->nbr_chunks = get_nbr_chunks(s);
}
