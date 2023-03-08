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

/* Check if identifier is equal. If its equal, return 1
*/
int	check_identifier(char *identifier)
{
	//printf("Identifier --> %s\n", identifier);
	if (ft_strncmp(identifier, "NO", 2) == 0
		|| ft_strncmp(identifier, "EA", 2) == 0
		|| ft_strncmp(identifier, "WE", 2) == 0
		|| ft_strncmp(identifier, "SO", 2) == 0
		|| ft_strncmp(identifier, "F", 1) == 0
		|| ft_strncmp(identifier, "C", 1) == 0)
	{
		return (1);
	}
	//printf("Bad sprite/color indentifier in map. Check it\n");
	return (0);
}

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
	{
		map_data->raw_data.no_route = malloc(ft_strlen(data) * sizeof(char *));
		ft_strlcpy(map_data->raw_data.no_route, data, ft_strlen(data) - 1);
	}
	else if (ft_strncmp(identifier, "EA", 2) == 0 && data != NULL)
	{
		map_data->raw_data.ea_route = malloc(ft_strlen(data) * sizeof(char *));
		ft_strlcpy(map_data->raw_data.ea_route, data, ft_strlen(data) - 1);
	}
	else if (ft_strncmp(identifier, "WE", 2) == 0 && data != NULL)
	{
		map_data->raw_data.we_route = malloc(ft_strlen(data) * sizeof(char *));
		ft_strlcpy(map_data->raw_data.we_route, data, ft_strlen(data) - 1);
	}
	else if (ft_strncmp(identifier, "SO", 2) == 0 && data != NULL)
	{
		map_data->raw_data.so_route = malloc(ft_strlen(data) * sizeof(char *));
		ft_strlcpy(map_data->raw_data.so_route, data, ft_strlen(data) - 1);
	}
	else if ((ft_strncmp(identifier, "F", 1) == 0 && data != NULL)
		|| (ft_strncmp(identifier, "C", 1) == 0 && data != NULL))
	color_assigner(identifier, data, map_data);
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

/* Check correct color values. Return color value.
	If color exceeds their correct range, return value will be rounded
	to limits.
	If color doesnt exist, return value will be 0
*/

int	check_color(char *color)
{
	int	c_value;

	if (color != NULL)
	{
		c_value = ft_atoi(color);
		if (c_value > 255)
			return (255);
		else if (c_value < 0)
			return (0);
		else
			return (c_value);
	}
	return (0);
}
