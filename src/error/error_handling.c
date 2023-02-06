/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:35:12 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/02 16:56:19 by hkaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error_alloc(void)
{
	printf("Fatal: error in memory allocation\n");
	exit(1);
}

void	error_file(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		write(2, &msg[i++], 1);
	exit(1);
}
