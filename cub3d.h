/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:55:14 by mcordoba          #+#    #+#             */
/*   Updated: 2023/04/12 19:21:23 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libs/key_macos.h"
# include "libs/libft/libft.h"
# include "parser/parser.h"
# include "raycast/raycast.h"
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

///////////////////////////////////////////
//	estructure for manage program
///////////////////////////////////////////
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		ancho;
	int		largo;
	int		count;
}			t_vars;

void	draw_minimap(t_vars *vars);
void	draw(t_vars *vars);
///////////////////////////////////////////
//	errmanag.c
///////////////////////////////////////////
void		errmanag(int argc, char *argv[]);
int			check_file_ext(char *file, char *ext);

///////////////////////////////////////////
//	file_manager.c
///////////////////////////////////////////
int			open_file_and_check_ext(char *file, char *ext);
void		close_file(int file_fd);

///////////////////////////////////////////
//	file_manager.c
///////////////////////////////////////////
void		freedom(char **matrix);
void		double_freedom(char **matrix, char *line);

#endif