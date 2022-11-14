/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:52:19 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/13 21:45:56 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (!line[i])
		error_file("Error:\nin the element");
	return (i);
}

static int	add_color_elem(t_data *data, char *line)
{
	int		i;
	int		j;
	int		nbr;
	char	**sp;

	i = 0;
	sp = ft_split(line, ',');
	add_split_garabage(data, sp);
	while (sp[i])
	{
		j = 0;
		//handle + sign too only not - sgin
		while (sp[i][j])
		{
			if (!(sp[i][j] >= '0' && sp[i][j] <= '9'))
				error_file("Error:\n in color");
			j++;
		}
		nbr = ft_atoi(sp[i]);
		if (!(nbr >= 0 && nbr <= 255))
			error_file("Error:\n invalid color");
		i++;
	}
	if (i != 3)
		error_file("Error:\n invalid RGB colors");
	return (color_converter(data, sp));
}

static void	parse_the_line(t_data *data, char *line)
{
	int		i;
	int		j;
	char	**elem;

	i = 0;
	elem = ft_split(ELEM, ' ');
	add_split_garabage(data, elem);
	while (elem[i])
	{
		if (!ft_strncmp(elem[i], line, ft_strlen(elem[i])))
			break ;
		i++;
	}
	if (!elem[i])
		error_file("Error:\ndifferent element in the map");
	else
	{
		j = ft_strlen(elem[i]);
		if (!line[j])
			error_file("Error:\nin the element");
		if (line[j] != ' ' && !(line[j] >= 9 && line[j] <= 13))
			error_file("Error:\ndifferent element in the map");
		j += skip_space(&line[j]);
		if (i >= 4)
		{
			if (i == 4)
			{
				if (data->color->floor)
					error_file("Error\nF already exist");
				data->color->floor = add_color_elem(data, &line[j]);
			}
			else
			{
				if (data->color->ceiling)
					error_file("Error\nC already exist");
				data->color->ceiling = add_color_elem(data, &line[j]);
			}
		}
		else
			if (!ft_strncmp(line, "NO", 2))
			{
				if (data->p_stat->north)
					error_file("Error\nNO already exist");
				data->p_stat->north = add_texture_elem(data, &line[j]);
			}
			if (!ft_strncmp(line, "SO", 2))
			{
				if (data->p_stat->south)
					error_file("Error\nSO already exist");
				data->p_stat->south = add_texture_elem(data, &line[j]);
			}
			if (!ft_strncmp(line, "EA", 2))
			{
				if (data->p_stat->east)
					error_file("Error\nEA already exist");
				data->p_stat->east = add_texture_elem(data, &line[j]);
			}
			if (!ft_strncmp(line, "WE", 2))
			{
				if (data->p_stat->west)
					error_file("Error\nWE already exist");
				data->p_stat->west = add_texture_elem(data, &line[j]);
			}
	}
}

void	parse_file(t_data *data)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	while (data->r_file[i])
	{
		line = ft_strtrim(data->r_file[i], "\t\v\r\f ");
		garbage_collector(data, line);
		if (len == 6 && line[0])
		{
			parse_map(data, &data->r_file[i]);
			return ;
		}
		else if (len < 6 && line[0])
		{
			len++;
			parse_the_line(data, line);
		}
		i++;
	}
	error_file("Error\nno existing for the map");
}
