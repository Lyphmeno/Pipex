/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:37:36 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/06 15:43:50 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == NULL)
		ft_exit_code("Error\nMalloc failed\n", 1);
	return (ft_memset(mem, 0, count * size));
}
