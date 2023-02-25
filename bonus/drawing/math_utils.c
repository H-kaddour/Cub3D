/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:51:11 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/24 13:28:07 by hkaddour         ###   ########.fr       */
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
