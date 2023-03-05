/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:55:14 by mcordoba          #+#    #+#             */
/*   Updated: 2023/03/05 18:55:14 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "../cub3d.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "../libs/libft/libft.h"

typedef struct s_rgbcol
{
	int			r;
	int			g;
	int			b;
}				t_rgbcol;

typedef struct s_rawdata
{
	char		*no_route;
	char		*so_route;
	char		*we_route;
	char		*ea_route;
	t_rgbcol	f_col;
	t_rgbcol	c_col;
}				t_rawdata;

typedef struct s_mapdata
{
	t_rawdata	raw_data;
}				t_mapdata;

///////////////////////////////////////////
//	parser.c
///////////////////////////////////////////
void	parser(char *cub_file);

///////////////////////////////////////////
//	data_assigner.c
///////////////////////////////////////////
void	data_assigner(char *data, t_mapdata **map_data);

#endif
