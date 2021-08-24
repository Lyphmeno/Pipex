/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:45:04 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/24 15:20:07 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	do_fcmd(t_data *data)
{
	dup2(data->firstfd, 0);
	dup2(data->fd[1], 1);
	close(data->fd[0]);
	close(data->fd[1]);
	execve(data->fcmd, data->fcmdarg, data->env);
}

void	do_scmd(t_data *data)
{
	dup2(data->secfd, 1);
	dup2(data->fd[0], 0);
	close(data->fd[0]);
	execve(data->scmd, data->scmdarg, data->env);
}

void	pipex(t_data *data)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		free_data(data);
		ft_exit_code("Error\n", 1);
	}
	else if (pid == 0)
		do_fcmd(data);
	close(data->fd[1]);
	pid = fork();
	if (pid == 0)
		do_scmd(data);
	close(data->fd[0]);
	waitpid(data->fd[0], &(data->status), 0);
	waitpid(data->fd[1], &(data->status), 0);
}

void	check_data(t_data **data)
{
	if ((*data)->firstfd < 0)
		ft_exit_code("Error\n", 1);
	if ((*data)->secfd < 0)
		ft_exit_code("Error\n", 1);
	(*data)->fcmdarg = ft_split((*data)->fcmd, ' ');
	get_path(data, 1);
	(*data)->scmdarg = ft_split((*data)->scmd, ' ');
	get_path(data, 2);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = NULL;
	if (argc != 5)
		ft_exit_code("Error\n", 1);
	data = ft_calloc(sizeof(t_data), 1);
	if (pipe(data->fd) == -1)
		ft_exit_code("Error\n", 1);
	data->firstfd = open(argv[1], O_RDONLY);
	data->secfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	data->fcmd = argv[2];
	data->scmd = argv[3];
	data->env = env;
	check_data(&data);
	pipex(data);
	close(data->firstfd);
	close(data->secfd);
	free_data(data);
	return (0);
}
