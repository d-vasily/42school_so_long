/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:54:45 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 14:39:18 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_error(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	map_error(char *s, int fd, char *error)
{
	if (s)
		free(s);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	close(fd);
	exit(1);
}
