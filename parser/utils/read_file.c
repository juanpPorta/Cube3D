/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:22:36 by marvin            #+#    #+#             */
/*   Updated: 2023/03/05 23:22:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	read_file(int file_fd, t_mapdata **map_data)
{
	char	*data_line;
	int		c;

	c = 0;
	printf("------------------------------\n");
	while (data_line)
	{
		data_line = get_next_line(file_fd);
		printf("Line %d is --> %s \n",c, data_line);
		if (data_line != NULL)
			data_assigner(data_line, map_data);
		printf("------------------------------\n");
		c++;
	}
	// data_line = get_next_line(file_fd);
	// printf("Line --> %s", data_line);
	// data_assigner(data_line, map_data);
	(void)map_data;
}
