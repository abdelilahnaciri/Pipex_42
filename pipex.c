/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 pipex.c											:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abnaciri <abnaciri@student.42.fr>			+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/22 12:56:38 by abnaciri		   #+#	  #+#			  */
/*	 Updated: 2024/03/06 18:22:07 by abnaciri		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	run_script_err(char **cmd_tab)
{
	ft_putstr_fd("Error: command not found: ", 2);
	ft_putstr_fd(cmd_tab[0], 2);
	ft_putstr_fd("\n", 2);
	ft_free_tab(cmd_tab);
	exit(0);
}

void	exec(char *cmd, char **env)
{
	char	**cmd_tab;
	char	*cmd_path;

	cmd_tab = ft_split(cmd, ' ');
	if (cmd[0] == '/')
		bad_path(cmd, cmd_tab);
	if (cmd[0] == '.' && cmd[1] == '/')
	{
		cmd++;
		while (*cmd == '/')
			cmd++;
		if (execve(cmd, cmd_tab, env) == -1)
			run_script_err(cmd_tab);
	}
	cmd_path = get_path(cmd_tab[0], env);
	if (execve(cmd_path, cmd_tab, env) == -1)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putstr_fd(cmd_tab[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_tab(cmd_tab);
		free(cmd_path);
		exit(0);
	}
}

void	child_process1(char **av, int *p_fd, char **env)
{
	int	input_fd;

	close(p_fd[0]);
	input_fd = open(av[1], O_RDONLY);
	if (input_fd < 0)
		ft_put_error("Error: Opening Input File	failed\n", 2);
	if (dup2(input_fd, 0) == -1)
		ft_put_error("Error: Replacing StdInput	by Input failed", 2);
	if (dup2(p_fd[1], 1) == -1)
		ft_put_error("Error: Replacing StdOut by Output failed", 2);
	close(input_fd);
	close(p_fd[1]);
	exec(av[2], env);
}

void	child_process2(char	**av, int *p_fd, char **env)
{
	int	output_fd;

	close(p_fd[1]);
	output_fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (output_fd < 0)
		ft_put_error("Error: Opening Output	File failed", 2);
	if (dup2(output_fd, 1) == -1)
		ft_put_error("Error: Replacing StdOut by Output	failed", 2);
	if (dup2(p_fd[0], 0) == -1)
		ft_put_error("Error: Replacing StdInput	by Output failed", 2);
	close(output_fd);
	close(p_fd[0]);
	exec(av[3], env);
}

int	main(int ac, char **av,	char **env)
{
	int		p_fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (ac != 5)
		ft_put_error("Error: Please	enter 5	agruments", 2);
	if (pipe(p_fd) == -1)
		ft_put_error("Error: Pipe Failed", 2);
	pid = fork();
	if (pid < 0)
		ft_put_error("Error: Fork Faild", 2);
	if (!pid)
		child_process1(av, p_fd, env);
	pid2 = fork();
	if (pid2 < 0)
		ft_put_error("Error: Fork Faild", 2);
	if (!pid2)
		child_process2(av, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
