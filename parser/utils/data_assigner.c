/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_assigner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:17:25 by marvin            #+#    #+#             */
/*   Updated: 2023/03/05 21:17:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* Assign data to their identifier. Data is passed by GNL_iterator
*/
void	data_assigner(char *data, t_mapdata *map_data)
{
	char	**split_data;

	//printf("Dataline --> %s\n", data);
	split_data = ft_split(data, ' ');
	//printf("Identifier --> %s\n", split_data[0]);
	//printf("DATA --> %s\n", split_data[1]);
	if (check_identifier(split_data[0]) == 1)
		assigner(split_data[0], split_data[1], map_data);
	freedom(split_data);
	(void)split_data;
	(void)map_data;
}

/* Find identifier and put the data into
*/
void	assigner(char *identifier, char *data, t_mapdata *map_data)
{
	if (ft_strncmp(identifier, "NO", 2) == 0 && data != NULL)
		route_assigner(&map_data->raw_data.no_route, data, map_data);
	else if (ft_strncmp(identifier, "EA", 2) == 0 && data != NULL)
		route_assigner(&map_data->raw_data.ea_route, data, map_data);
	else if (ft_strncmp(identifier, "WE", 2) == 0 && data != NULL)
		route_assigner(&map_data->raw_data.we_route, data, map_data);
	else if (ft_strncmp(identifier, "SO", 2) == 0 && data != NULL)
		route_assigner(&map_data->raw_data.so_route, data, map_data);
	else if ((ft_strncmp(identifier, "F", 1) == 0 && data != NULL)
		|| (ft_strncmp(identifier, "C", 1) == 0 && data != NULL))
	color_assigner(identifier, data, map_data);
}

/* Assign route data to their id in raw_map struct. Return 1 if data was allocated
*/
void	route_assigner(char **rawmap_id, char *data, t_mapdata *map_data)
{
	*rawmap_id = malloc(ft_strlen(data) * sizeof(char *));
	ft_strlcpy(*rawmap_id, data, ft_strlen(data) - 1);
	(void)map_data;
}

/* Split color data and assign it to their identifier
*/
void	color_assigner(char *identifier, char *data, t_mapdata *map_data)
{
	char	**split_data;

	split_data = ft_split(data, ',');
	if (ft_strncmp(identifier, "F", 1) == 0)
	{
		map_data->raw_data.f_col.r = check_color(split_data[0]);
		map_data->raw_data.f_col.g = check_color(split_data[1]);
		map_data->raw_data.f_col.b = check_color(split_data[2]);
	}
	else if (ft_strncmp(identifier, "C", 1) == 0)
	{
		map_data->raw_data.c_col.r = check_color(split_data[0]);
		map_data->raw_data.c_col.g = check_color(split_data[1]);
		map_data->raw_data.c_col.b = check_color(split_data[2]);
	}
	freedom(split_data);
}
