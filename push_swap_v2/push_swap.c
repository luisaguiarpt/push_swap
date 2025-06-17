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

int	main(int ac, char **av)
{
	t_core	*core;

	if (ac <= 2)
		exit_error();
	check_input(&av[1]);
	core = init_core();
	fill_stack_a(&av[1], core);
	upd_cost(core);
//	prt_lst(core->a);
	sort(core);
	free_all(core);
}

void	fill_stack_a(char **char_arr, t_core *core)
{
	int		i;

	i = 0;
	while (char_arr[i])
	{
		lstadd_back(core->a, lst_new(ft_atoi(char_arr[i])));
		i++;
	}
	core->size = lst_size(core->a);
	assign_attr(core);
}

void	prt_lst(t_stack **lst)
{
	t_stack	*ptr;
	int		i;

	ptr = *lst;
	i = 1;
	while (ptr)
	{
		ft_printf("%d: %+d -> cost: %d | index: %d | chunk: %d\n", i, ptr->value,
			ptr->cost, ptr->i, ptr->chunk);
		ptr = ptr->next;
		i++;
	}
}

void	prt_core(t_core *core)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;
	int		size_a = lst_size(core->a);
	int		size_b = lst_size(core->b);
	int		i = 0;

	ptr_a = *core->a;
	ptr_b = *core->b;
	ft_printf("-------------\n");
	while (i < size_a || i < size_b)
	{
		if (size_a > size_b + i)
		{
			ft_printf("%d (%d)", ptr_a->value, ptr_a->i);
			ft_printf(" |\n");
			ptr_a = ptr_a->next;
		}
		else if (size_b > size_a + i)
		{
			ft_printf("      | ");
			ft_printf("%d (%d)\n", ptr_b->value, ptr_b->i);
			ptr_b = ptr_b->next;
		}
		else
		{
			ft_printf("%d (%d) | %d (%d)\n", ptr_a->value, ptr_a->i, 
					ptr_b->value, ptr_b->i);
			ptr_a = ptr_a->next;
			ptr_b = ptr_b->next;
		}
		i++;
	}
	ft_printf("-------------\n");
	ft_printf("  a   |   b  \n");
	ft_printf("-------------\n");
}
