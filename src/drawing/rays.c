/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:32:12 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/06 17:54:10 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rays(t_data *data)
{
	data->draw_utils->x = data->draw_utils->ply_x_pos;
	data->draw_utils->y = data->draw_utils->ply_y_pos;
	data->draw_utils->x_next = data->draw_utils->x + cos(data->draw_utils->angle) * 30;
	data->draw_utils->y_next = data->draw_utils->y + sin(data->draw_utils->angle) * 30;
	//printf("x = %f, x_next = %f\n", data->draw_utils->x, data->draw_utils->x_next);
	//printf("y = %f, y_next = %f\n", data->draw_utils->y, data->draw_utils->y_next);
	dda(data, 0xff0000);
}
