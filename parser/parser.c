/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:02:22 by marvin            #+#    #+#             */
/*   Updated: 2023/03/05 20:02:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(char *cub_file)
{
	t_mapdata	*map_data;
	int			fd_map;

	map_data = NULL;
	printf("Parser\n");
	fd_map = open_file_and_check_ext(cub_file, ".cub");
	//printf("Map fd --> %d\n", fd_map);
	read_file(fd_map, &map_data);
	printf("NO data from RAW_DATA --> %s\n", map_data->raw_data.no_route);
	close_file(fd_map);
	(void)map_data;
	(void)cub_file;
}
