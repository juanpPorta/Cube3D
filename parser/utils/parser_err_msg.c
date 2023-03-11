/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_err_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:13:16 by marvin            #+#    #+#             */
/*   Updated: 2023/03/11 20:13:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* Print and exit program when identifier in .cub file is duplicated
*/
void	errmsg_two_ids(void)
{
	printf("[ERROR] Duplicated identifiers in .cub file\n");
	exit (1);
}
