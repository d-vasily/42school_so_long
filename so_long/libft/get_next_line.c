/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:53:24 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/10 15:45:33 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_part_str(char *s,
		size_t start, char end_char, int flag_free)
{
	size_t	end;
	char	*res;

	if (!s)
		s = (char *)ft_calloc(sizeof(char), 1);
	if (!s)
		return (0);
	end = start;
	while (s[end] && s[end] != end_char)
		end++;
	if (s[end] == end_char)
		end++;
	res = (char *)ft_calloc(sizeof(char), end - start + 1);
	if (flag_free && !res)
		free(s);
	if (!res)
		return (0);
	while (start < end--)
		res[end - start] = s[end];
	if (flag_free)
		free(s);
	return (res);
}

static char	*ft_add_arr(char **s, int fd)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	i = 0;
	while (s[fd] && s[fd][i] && s[fd][i] != '\n')
		i++;
	if (s[fd] && s[fd][i] == '\n')
		i++;
	res = (char *)ft_calloc(sizeof(char), i + 1);
	if (!res)
		return (0);
	j = 0;
	while (j++ < i)
		res[j - 1] = s[fd][j - 1];
	s[fd] = ft_get_part_str(s[fd], i, 0, 1);
	if (!s[fd])
		free(res);
	if (!s[fd])
		return (0);
	return (res);
}

static char	*ft_change_arr(char **arr, int fd, char *res)
{
	size_t	i;

	if (!res)
		return (0);
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	if (arr[fd])
		free(arr[fd]);
	arr[fd] = ft_get_part_str(res, i, 0, 0);
	if (!arr[fd])
	{
		free(res);
		return (0);
	}
	if (arr[fd][0] == 0)
	{
		free(arr[fd]);
		arr[fd] = 0;
	}
	res = ft_get_part_str(res, 0, '\n', 1);
	return (res);
}

static char	*ft_read(int fd, char **str_arr, char *s)
{
	int		len_read;
	char	*res;

	if (!s)
		return (0);
	len_read = read(fd, s, BUFFER_SIZE);
	res = (char *)ft_calloc(sizeof(char), 1);
	while (res && len_read > 0)
	{
		res = ft_strjoin1(res, s);
		if (!res)
			break ;
		if (ft_strchr(s, '\n'))
			break ;
		len_read = read(fd, s, BUFFER_SIZE);
		s[len_read] = 0;
	}
	res = ft_change_arr(str_arr, fd, res);
	free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str_arr[OPEN_MAX + 1];
	char		*str;
	char		*str_in;

	str = ft_add_arr(str_arr, fd);
	if (!str)
		return (0);
	if (ft_strchr(str, '\n'))
		return (str);
	str_in = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	str_in = ft_read(fd, str_arr, str_in);
	if (!str_in)
	{
		free(str);
		return (0);
	}
	str = ft_strjoin1(str, str_in);
	free(str_in);
	if (str && str[0] == 0)
	{
		free(str);
		return (0);
	}
	return (str);
}
