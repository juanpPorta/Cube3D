/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:00:32 by jporta            #+#    #+#             */
/*   Updated: 2023/04/05 16:05:04 by jporta           ###   ########.fr       */
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

void	draw(t_vars *vars)
{
	imgs *imgs;
	char	*fin;
	int		i;
	int  u = 0;

	imgs = 	malloc(1 * sizeof(imgs));
	i = 0;
	imgs->img = mlx_new_image(vars->mlx, 1000, 800);
	fin = mlx_get_data_addr(imgs->img, &imgs->bit_per_pixel, &imgs->size_line, &imgs->endian);
	while(u <= 1000)
	{	
		while (i <= (800 * 1000 * 2))
		{
			fin[i] = (char)254;
			i += 1000 * 4;
		}
		u++;
		i = u * 4;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, imgs->img, 0, 0);
	mlx_destroy_image(vars->mlx, imgs->img);
}
