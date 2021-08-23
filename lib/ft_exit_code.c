/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:35:19 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/18 18:00:07 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_code(char	*str, int x)
{
	ft_putstr_fd(str, 2);
	exit(x);
}