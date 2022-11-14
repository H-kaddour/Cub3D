/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:26:10 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/14 21:43:47 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*allocation(t_data *data, int count, int size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	garbage_collector(data, ptr);
	return (ptr);
}

char	*add_join(t_data *data, char *s, char *s1)
{
	char *ptr;

	ptr = ft_strjoin(s, s1);
	garbage_collector(data, ptr);
	return (ptr);
}

char	*add_dup(t_data *data, char *s)
{
	char *ptr;

	ptr = ft_strdup(s);
	garbage_collector(data, ptr);
	return (ptr);
}

char	*get_line_file(t_data *data, int fd)
{
	char *ptr;

	ptr = grab_line(fd);
	if (!ptr)
		return (0);
	garbage_collector(data, ptr);
	return (ptr);
}

void	init_data(t_data *data, char *file)
{
	data->n_file = file;
	data->g_collect = allocation(data, 1, sizeof(t_free));
	data->p_stat = allocation(data, 1, sizeof(p_stat));
	data->color = allocation(data, 1, sizeof(t_color));
	data->map = allocation(data, 1, sizeof(t_map));
	data->mlx = allocation(data, 1, sizeof(t_mlx));
	data->draw_utils = allocation(data, 1, sizeof(t_coord));

}
