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
		exit(1);
	stacks->a = malloc(sizeof(t_list));
	if (!stacks->a)
		free_malloc(stacks);
	stacks->b = malloc(sizeof(t_list));
	if (!stacks->b)
		free_malloc(stacks);
	return (stacks);
}

void	fill_stack_a(char **char_list, t_stacks *s)
{
	int		i;

	if (!check_array(char_list))
		free_all(s);
	i = 0;
	while (char_list[i])
	{
		lstadd_back(s->a, lst_new(ft_atoi(char_list[i])));
		i++;
	}
}
