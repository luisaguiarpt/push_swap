#include "checker.h"

int	main(int ac, char **av)
{
	char	**input;
	t_core	*core;

	if (ac < 2)
		exit_error();
	input = check_input(&av[1], ac);
	core = init_core();
	init_stack_a(core, input);
	core->print = 0;
	checker(core);
	free_all(core);
}

void	checker(t_core *core)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		do_op(core, ft_strtrim(line, "\n"));
		free(line);
		line = get_next_line(0);
	}
	if (is_ok(core))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	is_ok(t_core *core)
{
	t_stack	*prev;

	prev = *core->a;
	while (prev->next)
	{
		if (prev->value < prev->next->value)
			prev = prev->next;
		else
			return (0);
	}
	if (lst_size(core->b))
		return (0);
	return (1);
}

void	do_op(t_core *core, char *op)
{
	if (!ft_strcmp(op, "sa"))
		sa(core);
	else if (!ft_strcmp(op, "sb"))
		sb(core);
	else if (!ft_strcmp(op, "pa"))
		pa(core);
	else if (!ft_strcmp(op, "pb"))
		pb(core);
	else if (!ft_strcmp(op, "ra"))
		ra(core);
	else if (!ft_strcmp(op, "rb"))
		rb(core);
	else if (!ft_strcmp(op, "rra"))
		rra(core);
	else if (!ft_strcmp(op, "rrb"))
		rrb(core);
	else if (!ft_strcmp(op, "rr"))
		rr(core);
	else if (!ft_strcmp(op, "rrr"))
		rrr(core);
}
