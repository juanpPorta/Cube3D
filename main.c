/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:00:46 by mcordoba          #+#    #+#             */
/*   Updated: 2023/04/25 18:45:15 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cerrar(void)
{
	printf("Done!\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	printf("\t\033[0;35m----> Cub3d <----\033[0m\n");
	vars.mlx = mlx_init();
	vars.ancho = 800;
	vars.largo = 1000;
	vars.win = mlx_new_window(vars.mlx, vars.largo, vars.ancho, "cube");
	draw(&vars);
	// draw_minimap(&vars);
	mlx_hook(vars.win, 17, 1L << 17, cerrar, &vars);
	mlx_key_hook(vars.win, mlx_hook, &vars);
	mlx_loop(vars.mlx);
	errmanag(argc, argv);
	printf("\033[0;35m      ----> Cub3d END <----\033[0m\n");
	(void)argc;
	(void)argv;
	return (0);
}
