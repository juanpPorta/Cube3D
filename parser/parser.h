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

# include "../cub3d.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "../libs/libft/libft.h"

// Struct for save color in rgb mode
typedef struct s_rgbcol
{
	int			r;
	int			g;
	int			b;
}				t_rgbcol;

// Struct for check if data is already assigned
typedef struct s_dac
{
	/* data */
}				t_dac;

// Struct for save RAW data from .cub file
typedef struct s_rawdata
{
	char		*no_route;
	char		*so_route;
	char		*we_route;
	char		*ea_route;
	t_rgbcol	f_col;
	t_rgbcol	c_col;
}				t_rawdata;

// Main struct of parser
typedef struct s_mapdata
{
	t_rawdata	raw_data;
	int			fd_map;
	int			init;
}				t_mapdata;

///////////////////////////////////////////
//	parser.c
///////////////////////////////////////////
void	parser(char *cub_file);

///////////////////////////////////////////
//	read_file.c
///////////////////////////////////////////
void	read_file(int file_fd, t_mapdata *map_data);

///////////////////////////////////////////
//	data_assigner.c
///////////////////////////////////////////
void	data_assigner(char *data, t_mapdata *map_data);
void	assigner(char *identifier, char *data, t_mapdata *map_data);
void	color_assigner(char *identifier, char *data, t_mapdata *map_data);
void	route_assigner(char **rawmap_id, char *data, t_mapdata *map_data);

///////////////////////////////////////////
//	assigner_checkers.c
///////////////////////////////////////////
int		check_identifier(char *identifier);
int		check_color(char *color);

#endif
