/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:32:12 by hkaddour          #+#    #+#             */
/*   Updated: 2022/12/07 18:16:23 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < SQR_SIZE - 25)
	{
		mlx_put_pixel_to_img(data, data->draw_utils->ply_x_pos + 25, \
				data->draw_utils->ply_y_pos + 25 - i, 0xff0000);
		i++;
	}
}
