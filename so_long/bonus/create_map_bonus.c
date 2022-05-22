/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:26:57 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 12:33:07 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*cut_nl(char *str, t_game *map, int j)
{
	char	*s;
	int		i;

	if (!str)
		return (str);
	s = (char *)malloc(sizeof(char) * map->size.x);
	if (!s)
	{
		free(str);
		return (s);
	}
	i = -1;
	while (++i < map->size.x)
	{
		s[i] = str[i];
		if (s[i] == HERO)
		{
			map->x = i;
			map->y = j;
		}
	}
	free(str);
	return (s);
}

void	create_map(char *name, t_game *map)
{
	int		fd;
	int		j;

	fd = init_map(name, map);
	j = -1;
	map->map = (char **)malloc(sizeof(char *) * map->size.y);
	if (!map->map)
		map_error(0, fd, ERROR_MEMORY);
	while (++j < map->size.y)
	{
		map->map[j] = get_next_line(fd);
		map->map[j] = cut_nl(map->map[j], map, j);
		if (!map->map[j])
		{
			while (j-- > 0)
				free(map->map[j]);
			free(map->map);
			map_error(0, fd, ERROR_MEMORY);
		}
	}
	close(fd);
}
