/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:28:38 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/17 12:35:25 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
