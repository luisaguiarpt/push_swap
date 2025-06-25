/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:34:13 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/23 17:26:49 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check to see if all the elements in the list are integers
int	check_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (1);
	while (array[i])
	{
		if (!ft_isint(array[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[j])
		{
			if (!ft_strcmp(array[i], array[j]) && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**check_input(char **av, int ac)
{
	char **array;

	array = NULL;
	if (ac == 1)
		exit_error();
	else if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		if (check_array(array) || check_dup(array))
		{
			free(array);
			exit_error();
		}
	}
	else if (ac > 2)
	{
		if (check_array(av) || check_dup(av))
			exit_error();
		array = av;
	}
	return (array);
}

void	check_int(t_core *core)
{
	t_stack	*lst;

	lst = *core->a;
	while (lst)
	{
		if (lst->value > INT_MAX || lst->value < INT_MIN)
			free_error(core);
		lst = lst->next;
	}
}
