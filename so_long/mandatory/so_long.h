/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:53:58 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 14:43:44 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
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

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define CLICK_X 17

# define TILE 64
# define ANIMATION 10

# define PATH_EMPTY "./imgs/empty.xpm"
# define PATH_HERO "./imgs/hero.xpm"
# define PATH_WALL "./imgs/wall.xpm"
# define PATH_COLLECT "./imgs/collectible.xpm"
# define PATH_EXIT_O "./imgs/exit_open.xpm"
# define PATH_EXIT_C "./imgs/exit_closed.xpm"

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
	int			x;
	int			y;
	int			exit;
	int			exit_is_open;
	int			collectibles;
	int			moves;
	int			frames;
	char		under_player;
	char		**map;
	void		*mlx;
	void		*window;
}	t_game;

int		init_map(char *name, t_game *map);
void	create_map(char *name, t_game *map);
void	init_stuff(t_game *game);
int		key_hook(int keycode, t_game *g);
int		close_window(t_game *g);
int		render(t_game *game);
void	ft_put_error(char *error);
void	map_error(char *s, int fd, char *error);

#endif
