/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:53:03 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 14:44:14 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_game *game)
{
	ft_putstr_fd("Your won with number of moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	exit(0);
}

void	ft_put_moves(int n)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(n, 1);
	ft_putstr_fd("\n", 1);
}

void	move_handle(t_game *g, t_vector v)
{
	char	c;

	g->moves++;
	c = g->map[v.y][v.x];
	ft_put_moves(g->moves);
	if (c == COLLECTIBLES)
	{
		g->collectibles--;
		g->map[v.y][v.x] = EMPTY;
	}
	if (g->collectibles == 0)
		g->exit_is_open = 1;
	if (c == EXIT && g->exit_is_open)
		ft_win(g);
	g->y = v.y;
	g->x = v.x;
}

int	key_hook(int keycode, t_game *g)
{
	t_vector	d;

	if (keycode == ESC)
		exit(0);
	d.x = g->x;
	d.y = g->y;
	if (keycode == W)
		d.y -= 1;
	if (keycode == A)
		d.x -= 1;
	if (keycode == S)
		d.y += 1;
	if (keycode == D)
		d.x += 1;
	if ((d.x + d.y != g->x + g->y) && (g->map[d.y][d.x] != WALL))
		move_handle(g, d);
	return (0);
}

int	close_window(t_game *g)
{
	g->x = 0;
	exit(0);
	return (0);
}
