/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:53:35 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 12:16:43 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, int x, int y)
{
	char	c;
	void	*img;

	img = NULL;
	c = game->map[y][x];
	if (c == WALL)
		img = game->img.wall;
	else if (c == EXIT && game->exit_is_open == 1)
		img = game->img.exit_open;
	else if (c == EXIT && game->exit_is_open == 0)
		img = game->img.exit_close;
	else if (c == COLLECTIBLES)
		img = game->img.collectibles;
	else if (c == EMPTY || c == HERO)
		img = game->img.empty;
	mlx_put_image_to_window(game->mlx, game->window, img, x * TILE, y * TILE);
	if (x == game->x && y == game->y)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img.hero, \
				game->x * TILE, game->y * TILE + (game->frames > ANIMATION));
		game->frames++;
		if (game->frames > ANIMATION * 2)
			game->frames = 0;
	}
}

int	render(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->size.y)
	{
		x = -1;
		while (++x < game->size.x)
			put_img(game, x, y);
	}
	return (0);
}
