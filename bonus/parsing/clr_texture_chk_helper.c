/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_texture_chk_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:18:28 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/24 13:26:17 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_clr_error(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma >= 3)
		error_file("Error\ncolor has many section only takes RGB");
}

int	check_clr_range(char *nbr)
{
	int	n;

	if (ft_strlen(nbr) <= 3)
	{
		n = ft_atoi(nbr);
		if (n >= 0 && n <= 255)
			return (0);
	}
	return (1);
}
