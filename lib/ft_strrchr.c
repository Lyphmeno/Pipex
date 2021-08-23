/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:37:54 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/23 12:37:56 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*str;

	str = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			str = &s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return ((char *)str);
}
