/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:52:24 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/10 17:58:40 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *game)
{
	int		x;
	int		y;

	game->img.empty = mlx_xpm_file_to_image(game->mlx, PATH_EMPTY, &x, &y);
	game->img.hero = mlx_xpm_file_to_image(game->mlx, PATH_HERO, &x, &y);
	game->img.exit_open = mlx_xpm_file_to_image(game->mlx, PATH_EXIT_O, &x, &y);
	game->img.exit_close = mlx_xpm_file_to_image(game->mlx, \
			PATH_EXIT_C, &x, &y);
	game->img.collectibles = mlx_xpm_file_to_image(game->mlx, \
			PATH_COLLECT, &x, &y);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, PATH_WALL, &x, &y);
}

void	init_stuff(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, \
			game->size.x * TILE, game->size.y * TILE, "GAME");
	init_img(game);
}
