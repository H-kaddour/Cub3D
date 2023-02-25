/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:51:11 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/24 13:30:43 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	convert_rad2deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

double	convert_deg2rad(double degree)
{
	return (degree * (M_PI / 180.0));
}

// I will use it later on getting the angle right 0 to 360
//void	chk_degree_low_or_high(double angle)
//{
//	if ((int)round(convert_rad2deg(angle)) == 0)
//		angle = (2 * M_PI);
//	if ((int)round(convert_rad2deg(angle)) < 0)
//		angle = (2 * M_PI);
//	if ((int)round(convert_rad2deg(angle)) == 360)
//		angle = 0;
//}

//void	degree_is_high(double angle)
//{
//	if ((int)round(convert_rad2deg(angle)) == 0)
//		angle = 0;
//}
