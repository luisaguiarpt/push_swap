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

void	init_stack_a(char *str, t_stacks *s)
{
	char	**char_list;
	int		i;

	char_list = ft_split(str);
	if (!check_list(char_list))
		free_list(char_list);
	i = 0;
	while (char_list[i])
	{
		s->a
	}
}
