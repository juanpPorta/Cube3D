/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:00:32 by jporta            #+#    #+#             */
/*   Updated: 2023/03/21 17:57:35 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw(t_vars *vars)
{
	void	*img;
	int		bit_per_pixel;
	int		endian;
	int		size_line;
	char	*fin;
	int		i;
	int  u = 0;
	i = 0;
	img = mlx_new_image(vars->mlx, 1000, 800);
	fin = mlx_get_data_addr(img, &bit_per_pixel, &size_line, &endian);
	while(u <= 1000)
	{	
		while (i <= (800 * 1000 * 2))
		{
			fin[i] = (char)254;
			i += (4 * 1000);
		}
		u++;
		i = u * 4;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img, 0, 0);
	mlx_destroy_image(vars->mlx, img);
}
