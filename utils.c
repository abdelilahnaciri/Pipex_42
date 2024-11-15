/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 utils.c											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abnaciri <abnaciri@student.42.fr>			+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/22 14:08:44 by abnaciri		   #+#	  #+#			  */
/*	 Updated: 2024/03/06 14:33:49 by abnaciri		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_cmd_path(char	**env)
{
	char	*path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			path = env[i] + 5;
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char	*cmd, char **env)
{
	int		i;
	char	*exec_cmd;
	char	*path_part;
	char	**splited_path;

	i = 0;
	splited_path = ft_split(get_cmd_path(env), ':');
	if (!splited_path)
		exit(1);
	while (splited_path[i++])
	{
		path_part = ft_strjoin(splited_path[i], "/");
		exec_cmd = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec_cmd, F_OK) == 0)
			return (ft_free_tab(splited_path), exec_cmd);
		free(exec_cmd);
	}
	return (ft_free_tab(splited_path), NULL);
}

void	bad_path(char *cmd, char **cmd_tab)
{
	int	i;

	i = 0;
	while (cmd[i] == '/')
	{
		i++;
	}
	while (cmd[i] > 32 && cmd[i] != '/')
	{
		i++;
	}
	if (!cmd[i])
	{
		ft_putstr_fd("Error: no such file or directory: ", 2);
		ft_putstr_fd(*cmd_tab, 2);
		ft_putstr_fd("\n", 2);
		ft_free_tab(cmd_tab);
		exit(0);
	}
}

int	handle_grep(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (ft_strncmp(str, "grep", 4) == 0)
		{
			return (1);
		}
		str++;
	}
	return (0);
}
