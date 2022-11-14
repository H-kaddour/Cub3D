/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:50:05 by hkaddour          #+#    #+#             */
/*   Updated: 2022/11/14 13:47:04 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# define ELEM "NO SO EA WE F C"
# define WIN_W 1080
# define WIN_H 720
# include "../libft/libft.h"
# include "../gnl/gnl.h"
# include "draw.h"

typedef struct player_stat
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
} p_stat;

typedef struct s_color
{
	int	floor;
	int	ceiling;
} t_color;

typedef struct s_free
{
	void	*value;
	struct s_free *next;
} t_free;

typedef	struct s_map
{
	int		player_exist;
	char	player;
	int		width;
	int		height;
	char	**map;
} t_map;

typedef struct s_mlx
{
	void	*init;
	void	*win;
} t_mlx;

typedef struct s_coordinate t_coord;

typedef struct s_data
{
	char		*n_file;
	int			fd_map;
	char		**r_file;
	p_stat	*p_stat;
	t_color	*color;
	t_map		*map;
	t_mlx		*mlx;
	//struct s_coordinate	*draw_utils;
	t_coord	*draw_utils;
	t_free	*g_collect;
} t_data;


/******** Function of main **********/
void	init_data(t_data *data, char *file);
void	*allocation(t_data *data, int count, int size);
char	*add_dup(t_data *data, char *s);
char	*add_join(t_data *data, char *s, char *s1);
char	*get_line_file(t_data *data, int fd);


/******** Function of error **********/
void	error_alloc(void);
void	error_file(char *msg);


/******** Function of free **********/
void	garbage_collector(t_data *data, void *addr);
void	add_split_garabage(t_data *data, char	**elem);


/******** Function of parsing **********/
void	read_file(t_data *data);
void	parse_file(t_data *data);
char	*add_texture_elem(t_data *data, char *file);
int		color_converter(t_data *data, char **rgb);
void	parse_map(t_data *data, char **map);
void	check_map_error(t_data *data);

/******** Function of parsing **********/
void	window_init(t_data *data);
void	einstein_drawing(t_data *data);

#endif
