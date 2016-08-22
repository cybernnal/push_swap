/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:56:39 by tbillard          #+#    #+#             */
/*   Updated: 2016/05/20 18:28:41 by tbillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_lst(t_pile **p)
{
	t_pile *nex;

	while ((*p))
	{
		nex = (*p)->next;
		free(*p);
		(*p) = nex;
	}
	(*p) = NULL;
	p = NULL;
}