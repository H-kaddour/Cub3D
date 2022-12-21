/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:46:17 by hkaddour          #+#    #+#             */
/*   Updated: 2022/12/06 13:13:02 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_all(t_data *data)
{
	t_free	*prev;
	t_free	*trav;

	trav = data->g_collect;
	while (trav)
	{
		if (trav->value)
			free(trav->value);
		prev = trav;
		trav = trav->next;
		free(prev);
	}
}

void	garbage_collector(t_data *data, void *addr)
{
	t_free	*node;

	node = data->g_collect;
	if (!node)
		return ;
	while (node->next)
		node = node->next;
	node->next = ft_calloc(1, sizeof(t_free));
	node->next->value = addr;
}
