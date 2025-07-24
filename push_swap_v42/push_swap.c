/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:59:47 by ldias-da          #+#    #+#             */
/*   Updated: 2025/07/23 23:24:27 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_core	*core;
	char	**input;
	int		input_array;

	input_array = 0;
	if (ac == 1)
		exit(1);
	input = check_input(&input_array, &av[1], ac);
	core = init_core();
	core->input_arr = input;
	init_stack_a(core, input);
	if (core->size <= 3)
		sort_3(core);
	else if (core->size <= 5)
		sort_5(core);
	else
		sort(core);
	if (input_array)
		ft_free_tab(input);
	free_all(core);
}
