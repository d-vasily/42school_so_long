/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:51:42 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/10 18:15:31 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char *name)
{
	char	*s;
	int		i;
	int		len;
	int		ok;
	int		fd;

	i = 0;
	s = ".ber";
	len = ft_strlen(name);
	ok = (len > 4);
	while (i < 4 && ok)
	{
		ok -= (name[len - 4 + i] != s[i]);
		i++;
	}
	if (ok == 0)
		ft_put_error(ERROR_MAP_NAME);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_put_error(ERROR_NO_SUCH_FILE);
	return (fd);
}

void	handle_char(t_game *map, char *s, int i, int fd)
{
	int		ok;
	char	c;

	c = s[i];
	map->exit += (c == EXIT);
	map->x += (c == HERO);
	map->collectibles += (c == COLLECTIBLES);
	ok = (c == WALL) + (c == HERO) + (c == EMPTY);
	ok += (c == COLLECTIBLES) + (c == EXIT);
	if (!ok)
		map_error(s, fd, ERROR_CHAR);
}

int	check_line(char *s, t_game *map, int fd)
{
	int	len;
	int	i;
	int	walls;

	len = ft_strlen(s);
	len -= (s[len - 1] == '\n');
	if (len != map->size.x || len < 3)
		map_error(s, fd, ERROR_FORM);
	i = -1;
	walls = 0;
	while (++i < len)
	{
		handle_char(map, s, i, fd);
		walls += (s[i] == WALL);
	}
	map->size.y++;
	i = (s[0] == WALL && s[len - 1] == WALL);
	free(s);
	return ((1 + (walls != len)) * i);
}

void	check_valid_map(int fd, t_game *map)
{
	char	*s;
	int		ok;

	ok = 1;
	s = get_next_line(fd);
	if (!s)
		map_error(s, fd, ERROR_MEMORY);
	map->size.x = ft_strlen(s) - 1;
	ok = (check_line(s, map, fd) == 1);
	while (ok)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		ok = check_line(s, map, fd);
	}
	if (ok != 1)
		map_error(0, fd, ERROR_WALL);
	if (map->exit == 0)
		map_error(0, fd, ERROR_EXIT);
	if (map->collectibles == 0)
		map_error(0, fd, ERROR_COLLECTIBLES);
	if (map->x != 1)
		map_error(0, fd, ERROR_HERO);
}

int	init_map(char *name, t_game *map)
{
	int		fd;

	map->x = 0;
	map->y = 0;
	map->size.x = 0;
	map->size.y = 0;
	map->exit = 0;
	map->exit_is_open = 0;
	map->collectibles = 0;
	map->under_player = EMPTY;
	map->frames = 0;
	fd = check_map_name(name);
	check_valid_map(fd, map);
	fd = open(name, O_RDONLY);
	return (fd);
}
