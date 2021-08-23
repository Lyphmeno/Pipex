/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:45:04 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/23 13:35:09 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	check_data(t_data *data)
{
	if (data->firstfd < 0)
		ft_exit_code("Error\n", 1);
	if (data->secfd < 0)
		ft_exit_code("Error\n", 1);

}

int		main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = NULL;
	if (argc != 5)
		ft_exit_code("Error\n", 1);
	data = ft_calloc(sizeof(t_data), 1);
	if (pipe(data->fd) == -1)
		ft_exit_code("Error\n", 1);
	data->firstfd = open(argv[1], O_RDONLY);
	data->secfd = open(argv[4], O_RDONLY);
	data->firstcmd = argv[2];
	data->seccmd = argv[3];
	data->env = env;
	check_data(data);
	free(data);
	return (0);
}
