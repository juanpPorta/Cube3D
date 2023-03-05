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

#ifndef CUB3D_H
# define CUB3D_H

# include "parser/parser.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libs/libft/libft.h"
# include "libs/key_macos.h"

///////////////////////////////////////////
//	errmanag.c
///////////////////////////////////////////
void	errmanag(int argc, char *argv[]);
int		check_file_ext(char *file, char *ext);

///////////////////////////////////////////
//	file_manager.c
///////////////////////////////////////////
int		open_file_and_check_ext(char *file, char *ext);
void	close_file(int file_fd);


#endif