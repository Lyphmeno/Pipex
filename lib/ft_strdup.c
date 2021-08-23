/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:26:53 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/23 12:57:15 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	slen;
	size_t	i;
	char	*res;

	slen = ft_strlen((char *)src);
	i = 0;
	res = (char *)malloc(sizeof(char) * slen + 1);
	if (!res)
		return (0);
	while (i < slen)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
