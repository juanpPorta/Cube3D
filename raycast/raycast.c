/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:00:32 by jporta            #+#    #+#             */
/*   Updated: 2023/04/26 20:25:30 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

typedef struct t_img
{
	void	*img;
	int		bit_per_pixel;
	int		endian;
	int		size_line;
} imgs;

// void	draw_V2(imgs *img)
// {
	
// }

void	draw(t_vars *vars)
{
	imgs *imgs;
	char	*fin;
	int		i;
	int  u = 0;
			//1000 ancho 800 largo
	imgs = 	malloc(1 * sizeof(imgs));
	imgs->img = mlx_new_image(vars->mlx, vars->largo, vars->ancho);
	fin = mlx_get_data_addr(imgs->img, &imgs->bit_per_pixel, &imgs->size_line, &imgs->endian);
	u = 0;
	int z;
	i = 1;
	while (u < vars->ancho)
	{	
		z = 0;
		while (z < (vars->largo))
		{
			fin[i] = (char)240;
			fin[i + 1] = (char)240;
			fin[i + 2] = (char)240;
			if(z % 200 == 0 || u %200 == 0)
			{
				fin[i + 1] = (char)0;
				fin[i + 2] = (char)0;
			}
			i += 4;
			z += 1;
		}
		u++;
		// z += 200;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, imgs->img, 0, 0);
	mlx_destroy_image(vars->mlx, imgs->img);
	free(imgs);
}


