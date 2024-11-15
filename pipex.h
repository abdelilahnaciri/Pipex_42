/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 pipex.h											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abnaciri <abnaciri@student.42.fr>			+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/22 15:12:01 by abnaciri		   #+#	  #+#			  */
/*	 Updated: 2024/03/06 12:58:03 by abnaciri		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_path(char	*cmd, char **env);
void	exec(char *cmd, char **env);
void	ft_free_tab(char **tab);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char	const *s, char c);
char	*ft_strjoin(char const *s1,	char const *s2);
int		ft_strncmp(const char *str1, const char	*str2, size_t n);
void	ft_put_error(char *s, int fd);
void	bad_path(char *cmd, char **cmd_tab);
int		handle_grep(char *str);

#endif