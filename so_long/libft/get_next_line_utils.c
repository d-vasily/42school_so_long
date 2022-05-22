/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelroy <eelroy@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:39:13 by eelroy            #+#    #+#             */
/*   Updated: 2022/04/10 16:26:14 by eelroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*s;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *)ft_calloc(sizeof(char), len);
	i = 0;
	while (s && s1[i++])
		s[i - 1] = s1[i - 1];
	j = 0;
	while (s && s2[j++])
		s[j + i - 2] = s2[j - 1];
	free(s1);
	return (s);
}
