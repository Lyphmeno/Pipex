/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:59:49 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/24 15:20:39 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->fcmdarg[i])
		free(data->fcmdarg[i++]);
	free(data->fcmdarg);
	i = 0;
	while (data->scmdarg[i])
		free(data->scmdarg[i++]);
	free(data->scmdarg);
	free(data->fcmd);
	free(data->scmd);
	free(data);
}

char	*init_path(char **env)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (!(ft_strncmp("PATH=", env[i], 5)))
		{
			path = ft_strdup(ft_strrchr(env[i], '=') + 1);
			break ;
		}
		i++;
	}
	return (path);
}

int	join_path(char **cmd_arr, char *path, char *arg)
{
	char	*cmd;
	char	*tmp;

	cmd = ft_strjoin(path, "/");
	tmp = cmd;
	cmd = ft_strjoin(cmd, arg);
	free(tmp);
	if (open(cmd, O_RDONLY) > 0)
	{
		*cmd_arr = ft_strdup(cmd);
		free(cmd);
		return (1);
	}
	free(cmd);
	return (0);
}

void	get_path(t_data **data, int cmd)
{
	int		i;
	int		check;
	char	*path;
	char	**path_arr;

	i = 0;
	check = 0;
	path = init_path((*data)->env);
	path_arr = ft_split(path, ':');
	while (path_arr[i] && !check)
	{
		if (cmd == 1)
			check = join_path(&(*data)->fcmd, path_arr[i], (*data)->fcmdarg[0]);
		if (cmd == 2)
			check = join_path(&(*data)->scmd, path_arr[i], (*data)->scmdarg[0]);
		i++;
	}
	i = 0;
	while (path_arr[i])
		free(path_arr[i++]);
	free(path);
	free(path_arr);
	if (!check)
		ft_exit_code("Error\n", 1);
}
