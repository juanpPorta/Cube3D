/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:00:32 by jporta            #+#    #+#             */
/*   Updated: 2023/04/24 17:53:47 by jporta           ###   ########.fr       */
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
	i = 0;
	imgs->img = mlx_new_image(vars->mlx, vars->largo, vars->ancho);
	fin = mlx_get_data_addr(imgs->img, &imgs->bit_per_pixel, &imgs->size_line, &imgs->endian);
	while (u <= vars->ancho)
	{	
		while (i <= (vars->ancho * vars->largo * 4))
		{
			fin[i] = (char)254;
			i += vars->largo;
		}
		u++;
		i = u * 4;
	}
	i = 0;
	u = 0;
	while (u <= vars->ancho)
	{	
		while (i <= (vars->ancho * vars->largo * 4))
		{
			if (i == 250*4)
			{
				fin[i] = (char)0;
			}
			else
				fin[i] = (char)254;
			i += vars->largo;
		}
		u++;
		i = u * 4;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, imgs->img, 0, 0);
	mlx_destroy_image(vars->mlx, imgs->img);
}


