/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:18:52 by marvin            #+#    #+#             */
/*   Updated: 2023/03/11 18:18:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

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