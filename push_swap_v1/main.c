/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:55:22 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:06:26 by ldias-da         ###   ########.fr       */
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

int	main(void)
{
	t_list	*lsta = lst_new(1);
	lsta->next = lst_new(2);
	lsta->next->next = lst_new(3);

	t_list	*lstb = lst_new(4);
	lstb->next = lst_new(5);
	lstb->next->next = lst_new(6);

	t_stacks	*s = malloc(sizeof(t_stacks));
	s->a = &lsta;
	s->b = &lstb;

	ft_printf("----------Start-----------\n");
	ft_printf("List A size: %i\n", lst_size(s->a));
	prt_lst(s->a);
	ft_printf("List B size: %i\n", lst_size(s->b));
	prt_lst(s->b);

	ft_printf("----------Swap both-----------\n");
	ss(s);
	ft_printf("List A size: %i\n", lst_size(s->a));
	prt_lst(s->a);
	ft_printf("List B size: %i\n", lst_size(s->b));
	prt_lst(s->b);

	ft_printf("----------Push A-----------\n");
	pa(s);
	ft_printf("List A size: %i\n", lst_size(s->a));
	prt_lst(s->a);
	ft_printf("List B size: %i\n", lst_size(s->b));
	prt_lst(s->b);

	ft_printf("----------Check last B-----------\n");
	ft_printf("Last B: %i\n", lst_last(s->b)->value);
	ft_printf("Second last B: %i\n", lst_2ndlast(s->b)->value);

	ft_printf("----------Check last A-----------\n");
	ft_printf("Last A: %i\n", lst_last(s->a)->value);
	ft_printf("Second last A: %i\n", lst_2ndlast(s->a)->value);

	ft_printf("----------Rotate A-----------\n");
	ra(s);
	ft_printf("List A size: %i\n", lst_size(s->a));
	prt_lst(s->a);
	ft_printf("List B size: %i\n", lst_size(s->b));
	prt_lst(s->b);

	ft_printf("----------Reverse rotate A-----------\n");
	rra(s);
	ft_printf("List A size: %i\n", lst_size(s->a));
	prt_lst(s->a);
	ft_printf("List B size: %i\n", lst_size(s->b));
	prt_lst(s->b);

	ft_printf("----------Reverse rotate Both-----------\n");
	rrr(s);
	ft_printf("List A size: %i\n", lst_size(s->a));
	prt_lst(s->a);
	ft_printf("List B size: %i\n", lst_size(s->b));
	prt_lst(s->b);

}
