/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:28:22 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 12:55:32 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_moves(t_game *g)
{
	char	*n;

	n = ft_itoa(g->moves);
	mlx_string_put(g->mlx, g->window, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(g->mlx, g->window, 110, 10, 0xFFFFFF, n);
	free(n);
}

void	put_hero(t_game *game)
{
	int	x;
	int	y;

	x = game->x * TILE;
	y = game->y * TILE + 2 * (game->frames_h > ANIMATION_H);
	mlx_put_image_to_window(game->mlx, game->window, game->img.hero, x, y);
	game->frames_h++;
	if (game->frames_h > ANIMATION_H * 2)
		game->frames_h = 0;
}

void	*get_enemy(t_game *game)
{
	int	i;

	if (game->frames_e == 0)
		game->enemy_frame = 1;
	else if (game->frames_e == ANIMATION_E)
	{
		game->frames_e = 89;
		game->enemy_frame = -1;
	}
	i = game->frames_e / 10;
	game->frames_e += game->enemy_frame;
	return (game->enemy[i]);
}

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
	else if (c == ENEMY)
		img = get_enemy(game);
	mlx_put_image_to_window(game->mlx, game->window, img, x * TILE, y * TILE);
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
	put_hero(game);
	put_moves(game);
	return (0);
}
