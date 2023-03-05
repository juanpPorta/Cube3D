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

/* Check if identifier is equal
*/
int	check_identifier(char *identifier)
{
	printf("Identifier --> %s\n", identifier);
	if (ft_strncmp(identifier, "NO", 2) != 0
		&& ft_strncmp(identifier, "EA", 2) != 0
		&& ft_strncmp(identifier, "WE", 2) != 0
		&& ft_strncmp(identifier, "SO", 2) != 0
		&& ft_strncmp(identifier, "F", 1) != 0
		&& ft_strncmp(identifier, "C", 1) != 0)
	{
		printf("Bad sprite/color indentifier in map. Check it\n");
	}
	return (1);
}

/* Assign data to their identifier. Data is passed by GNL_iterator
*/
void	data_assigner(char *data, t_mapdata **map_data)
{
	char	**split_data;

	split_data = ft_split(data, ' ');
	check_identifier(split_data[0]);
	(void)split_data;
	(void)map_data;
}
