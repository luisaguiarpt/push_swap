/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:58:51 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/23 18:59:01 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	char	**input;
	t_core	*core;
	int		input_array;

	if (ac == 1)
		exit(1);
	input_array = 0;
	input = check_input(&input_array, &av[1], ac);
	core = init_core();
	core->input_arr = input;
	init_stack_a(core, input);
	core->print = 0;
	checker(core);
	if (input_array)
		ft_free_tab(input);
	free_all(core);
}

void	checker(t_core *core)
{
	char	*line;
	char	*trim_line;

	line = get_next_line(0);
	while (line)
	{
		trim_line = ft_strtrim(line, "\n");
		do_op(core, trim_line);
		free(line);
		free(trim_line);
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
	while (prev && prev->next)
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
