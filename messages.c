/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:48:15 by ldias-da          #+#    #+#             */
/*   Updated: 2025/05/30 17:55:04 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	disp_error(int error)
{
	if (error == 1)
	{
		ft_printf("No arguments passed.\n");
		ft_printf("Usage: ./push_swap <list of values>\n");
	}
}
