/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:40:56 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:48:16 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prt_lst(t_list **lst)
{
	t_list *ptr;
   
	ptr = *lst;

	while (ptr)
	{
		ft_printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
}

int	main(int ac, char **av)
{
	t_stacks	*s;
	
	if (ac <= 2)
		exit_error();
	s = init_stacks();
	fill_stack_a(&av[1], s);
	prt_lst(s->a);
	free_all(s);
}
