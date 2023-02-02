/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <hkaddour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:35:12 by hkaddour          #+#    #+#             */
/*   Updated: 2023/02/01 18:20:31 by hkaddour         ###   ########.fr       */
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
	printf("%s\n", msg);
	exit(1);
}
