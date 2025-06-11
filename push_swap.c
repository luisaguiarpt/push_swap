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
	t_list	*ptr;
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

void	prt_stacks(t_stacks *s)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	int		size_a = lst_size(s->a);
	int		size_b = lst_size(s->b);
	int		i = 0;

	ptr_a = *s->a;
	ptr_b = *s->b;
	ft_printf("\n");
	while (i < size_a || i < size_b)
	{
		if (size_a > size_b + i)
		{
			ft_printf("%d", ptr_a->value);
			ft_printf(" |\n");
			ptr_a = ptr_a->next;
		}
		else if (size_b > size_a + i)
		{
			ft_printf("  | ");
			ft_printf("%d\n", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
		{
			ft_printf("%d | %d\n", ptr_a->value, ptr_b->value);
			ptr_a = ptr_a->next;
			ptr_b = ptr_b->next;
		}
		i++;
	}
	ft_printf("-----\n");
	ft_printf("a | b\n");
}

int	main(int ac, char **av)
{
	t_stacks	*s;

	if (ac <= 2)
		exit_error();
	check_input(&av[1]);
	s = init_stacks();
	fill_stack_a(&av[1], s);
	get_cost(s);
	ft_printf("Size: %d\n", s->size);
	prt_lst(s->a);
	s->chunk_sizes = get_chunk_sizes(s);
	ft_printf("Nbr of chunks: %d\n", s->nbr_chunks);
	for (int i = 0; i < s->nbr_chunks; i++)
		ft_printf("Chunk %d size: %d\n", i, s->chunk_sizes[i]);
	get_cheapest_chunk(s);
//	prt_stacks(s);
//	pb(s);
//	prt_stacks(s);
//	pb(s);
//	prt_stacks(s);
//	pb(s);
//	prt_stacks(s);
//	pb(s);
//	prt_stacks(s);
//	pb(s);
//	prt_stacks(s);
//	pb(s);
//	prt_stacks(s);
//	pa(s);
//	prt_stacks(s);
	free_all(s);
}
