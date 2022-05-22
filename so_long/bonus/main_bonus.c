/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:28:07 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 12:33:52 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd(ERROR_ARGC, 2);
		exit(1);
	}
	create_map(argv[1], &game);
	init_stuff(&game);
	mlx_key_hook(game.window, key_hook, &game);
	mlx_hook(game.window, CLICK_X, 0, close_window, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
}
