#include "push_swap.h"

int	main(int ac, char **av)
{
	t_core	*core;

	if (ac <= 2)
		exit_error();
	check_input(&av[1]);
	core = init_core();
	init_stack_a(core, &av[1]);
	sort(core);
}
