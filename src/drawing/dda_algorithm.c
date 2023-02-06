/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:00:41 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/06 16:00:56 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//int	bigg(int a, int b)
//{
//	if (a > b)
//		return (a);
//	return (b);
//}

void	dda(t_data *data, int	loun)
{
	double	dx;
	double	dy;
	double	big;

	dx = data->draw_utils->x_next - data->draw_utils->x;
	dy = data->draw_utils->y_next - data->draw_utils->y;
	big = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	//big = bigg(abs((int)dx), abs((int)dy));
	dx /= big;
	dy /= big;
	while ((int)(data->draw_utils->x_next - data->draw_utils->x) || \
			(int)(data->draw_utils->y_next - data->draw_utils->y))
	{
		mlx_put_pixel_to_img(data, data->draw_utils->x, data->draw_utils->y, loun);
		data->draw_utils->x += dx;
		data->draw_utils->y += dy;
	}
}
