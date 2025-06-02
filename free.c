/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:39:10 by ldias-da          #+#    #+#             */
/*   Updated: 2025/06/02 17:43:07 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(char ***char_list)
{
	int		i;

	i = 0;
	while (*char_list[i])
	{
		free(*char_list[i]);
		i++;
	}
	free(*char_list);
	*char_list = NULL;
}
