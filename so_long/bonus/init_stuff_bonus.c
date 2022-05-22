/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:27:32 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 12:33:34 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	game->enemy[0] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_0, &x, &y);
	game->enemy[1] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_1, &x, &y);
	game->enemy[2] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_2, &x, &y);
	game->enemy[3] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_3, &x, &y);
	game->enemy[4] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_4, &x, &y);
	game->enemy[5] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_5, &x, &y);
	game->enemy[6] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_6, &x, &y);
	game->enemy[7] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_7, &x, &y);
	game->enemy[8] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_8, &x, &y);
	game->enemy[9] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_9, &x, &y);
}

void	init_stuff(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, \
			game->size.x * TILE, game->size.y * TILE, "GAME");
	init_img(game);
}
