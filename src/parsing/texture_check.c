/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:02:06 by hkaddour          #+#    #+#             */
/*   Updated: 2022/10/30 17:34:37 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*add_texture_elem(t_data *data, char *file)
{
	int		fd;
	int		len;
	char	*texture;

	len = ft_strlen("./textures/");
	texture = 0;
	if (ft_strncmp(file, "./textures/", len))
		error_file("Error:\nInvalid texture");
	if (file[len] && (file[len] == ' ' || (file[len] >= 9 && file[len] <= 13)))
		error_file("Error:\nInvalid texture");
	else
	{
		len = ft_strlen(file);
		texture = allocation(data, len + 1, sizeof(char));
		ft_strlcpy(texture, file, len + 1);
		fd = open(texture, O_RDONLY);
		if (fd < 0)
			error_file("Error:\nInvalid texture file");
	}
	return (texture);
}
