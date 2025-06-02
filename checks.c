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

#include "push_swap.c"

// Check to see if all the elements in the list are integers
int	check_list(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!ft_isint(array[i]))
			return (0);
		i++;
	}
	return (1);
}
