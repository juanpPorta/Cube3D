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

// /* Check if identifier is equal
// */
// int		check_identifier(char *identifier)
// {
// 	if (identifier != "NO" || identifier != "EA" || identifier != "WE" ||
// 		identifier != "SO" || identifier != "F" || identifier != "C")
// 			return (0);
// 	return (1);
// }


/* Assign data to their identifier. Data is passed by GNL_iterator
*/
void	data_assigner(char *data, t_mapdata **map_data)
{
	char	**split_data;
	
	split_data = ft_split(data, ' ');
	(void)split_data;
	(void)map_data;
}
