/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:34:13 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:46:13 by ldias-da         ###   ########.fr       */
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

void	check_input(char **array)
{
	if (check_array(array) || check_dup(array))
		exit_error();
	return ;
}
