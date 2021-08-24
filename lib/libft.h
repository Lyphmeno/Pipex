/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:27:21 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/24 15:19:49 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd[2];
	int		firstfd;
	int		secfd;
	char	*fcmd;
	char	*scmd;
	char	**fcmdarg;
	char	**scmdarg;
	char	**env;
	int		status;
}			t_data;

// LIB basics
void	*ft_calloc(size_t count, size_t size);
void	ft_exit_code(char	*str, int x);
void	*ft_memset(void *b, int c, size_t len);
void	**ft_newarray(size_t w, size_t h, size_t size);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *s, char c);
void	ft_strcat(char *dst, char *src);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
// Path
void	free_data(t_data *data);
char	*init_path(char **env);
int		join_path(char **cmd_arr, char *path, char *arg);
void	get_path(t_data **data, int cmd);
// Pipex
void	do_fcmd(t_data *data);
void	do_scmd(t_data *data);
void	check_data(t_data **data);
void	pipex(t_data *data);
#endif