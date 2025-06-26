#include "push_swap.h"

// Need to check if number is int (bigger or smaller than - use long)
// need to check if it's sorted to begin with to prevent starting if it's already sorted

int	main(int ac, char **av)
{
	t_core	*core;
	char	**input;

	if (ac < 2)
		exit_error();
	input = check_input(&av[1], ac);
	core = init_core();
	init_stack_a(core, input);
	if (core->size <= 3)
		sort_3(core);
	else if (core->size <= 5)
		sort_5(core);
	else
		sort(core);
	free_all(core);
}

void	prt_lst(t_stack **lst)
{
	t_stack	*ptr;
	int		i;

	ptr = *lst;
	i = 1;
	while (ptr)
	{
		ft_printf("%d: %+d -> moves: %d | cost: %d | index: %d\n", i, ptr->value,
			ptr->moves, ptr->cost, ptr->index);
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
			ft_printf("%d (%d)", ptr_a->value, ptr_a->index);
			ft_printf(" |\n");
			ptr_a = ptr_a->next;
		}
		else if (size_b > size_a + i)
		{
			ft_printf("      | ");
			ft_printf("%d (%d)\n", ptr_b->value, ptr_b->index);
			ptr_b = ptr_b->next;
		}
		else
		{
			ft_printf("%d (%d) | %d (%d)\n", ptr_a->value, ptr_a->index, 
					ptr_b->value, ptr_b->index);
			ptr_a = ptr_a->next;
			ptr_b = ptr_b->next;
		}
		i++;
	}
	ft_printf("-------------\n");
	ft_printf("  a   |   b  \n");
	ft_printf("-------------\n");
}
