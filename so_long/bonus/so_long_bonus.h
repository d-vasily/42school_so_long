/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:28:52 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 13:07:21 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/libft.h"
# include <mlx.h>

# define ERROR_WALL "Wall position isn't right."
# define ERROR_MAP_NAME "Map name isn't right."
# define ERROR_NO_SUCH_FILE "Can't find file with this name."
# define ERROR_EXIT "The number of exits is incorrect."
# define ERROR_COLLECTIBLES "The number of collectibles is wrong."
# define ERROR_HERO "The number of heroes is wrong."
# define ERROR_MEMORY "Malloc error."
# define ERROR_FORM "Incorrect form."
# define ERROR_CHAR "Incorrect symbol."
# define ERROR_ARGC "Incorrect number of arguments."

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLES 'C'
# define EXIT 'E'
# define HERO 'P'
# define ENEMY 'Z'

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define CLICK_X 17

# define TILE 64
# define ANIMATION_H 10
# define ANIMATION_E 100

# define PATH_EMPTY "./imgs/empty.xpm"
# define PATH_HERO "./imgs/hero.xpm"
# define PATH_WALL "./imgs/wall.xpm"
# define PATH_COLLECT "./imgs/collectible.xpm"
# define PATH_EXIT_O "./imgs/exit_open.xpm"
# define PATH_EXIT_C "./imgs/exit_closed.xpm"

# define PATH_ENEMY_0 "./imgs/enemy/lava_0.xpm"
# define PATH_ENEMY_1 "./imgs/enemy/lava_1.xpm"
# define PATH_ENEMY_2 "./imgs/enemy/lava_2.xpm"
# define PATH_ENEMY_3 "./imgs/enemy/lava_3.xpm"
# define PATH_ENEMY_4 "./imgs/enemy/lava_4.xpm"
# define PATH_ENEMY_5 "./imgs/enemy/lava_5.xpm"
# define PATH_ENEMY_6 "./imgs/enemy/lava_6.xpm"
# define PATH_ENEMY_7 "./imgs/enemy/lava_7.xpm"
# define PATH_ENEMY_8 "./imgs/enemy/lava_8.xpm"
# define PATH_ENEMY_9 "./imgs/enemy/lava_9.xpm"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void		*empty;
	void		*hero;
	void		*exit_open;
	void		*exit_close;
	void		*collectibles;
	void		*wall;
}	t_img;

typedef struct s_game
{
	t_vector	size;
	t_img		img;
	void		*enemy[10];
	int			x;
	int			y;
	int			exit;
	int			exit_is_open;
	int			collectibles;
	int			moves;
	int			frames_h;
	int			frames_e;
	int			enemy_frame;
	char		under_player;
	char		**map;
	void		*mlx;
	void		*window;
}	t_game;

int		init_map(char *name, t_game *map);
void	create_map(char *name, t_game *map);
void	init_stuff(t_game *game);
int		key_hook(int keycode, t_game *g);
int		render(t_game *game);
int		close_window(t_game *g);
void	ft_put_error(char *error);
void	map_error(char *s, int fd, char *error);

#endif
