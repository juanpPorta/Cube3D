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
	if (ft_strncmp(identifier, "NO", 2) == 0)
	{
		map_data->raw_data.no_route = malloc(ft_strlen(data) * sizeof(char *) - 1);
		ft_strlcpy(map_data->raw_data.no_route, data, ft_strlen(data) - 1);
	}
	else if (ft_strncmp(identifier, "EA", 2) == 0)
	{
		map_data->raw_data.ea_route = malloc(ft_strlen(data) * sizeof(char *) - 1);
		ft_strlcpy(map_data->raw_data.ea_route, data, ft_strlen(data) - 1);
	}
	else if (ft_strncmp(identifier, "WE", 2) == 0)
	{
		map_data->raw_data.we_route = malloc(ft_strlen(data) * sizeof(char *) - 1);
		ft_strlcpy(map_data->raw_data.we_route, data, ft_strlen(data) - 1);
	}
	else if (ft_strncmp(identifier, "SO", 2) == 0)
	{
		map_data->raw_data.so_route = malloc(ft_strlen(data) * sizeof(char *) - 1);
		ft_strlcpy(map_data->raw_data.so_route, data, ft_strlen(data) - 1);
	}



}
