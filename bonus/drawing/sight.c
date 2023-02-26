/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:05:10 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/26 12:33:29 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	is_view_up(t_data *data)
{
	if (data->ray->angle_chk >= (double)180 && \
			data->ray->angle_chk <= (double)360)
		return (1);
	return (0);
}

int	is_view_right(t_data *data)
{
	if ((data->ray->angle_chk >= (double)270 && \
			data->ray->angle_chk <= (double)360) || \
			(data->ray->angle_chk >= (double)0 && \
			data->ray->angle_chk <= (double)90))
		return (1);
	return (0);
}

int	is_view_down(t_data *data)
{
	if (!is_view_up(data))
		return (1);
	return (0);
}

int	is_view_left(t_data *data)
{
	if (!is_view_right(data))
		return (1);
	return (0);
}
