/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:46:17 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/13 15:40:43 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	add_split_garabage(t_data *data, char	**elem)
{
	while (*elem)
		garbage_collector(data, *elem++);
	garbage_collector(data, elem);
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
	node->value = addr;
}
