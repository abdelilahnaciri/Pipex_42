/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 ft_put_error.c										:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abnaciri <abnaciri@student.42.fr>			+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/03/06 12:41:15 by abnaciri		   #+#	  #+#			  */
/*	 Updated: 2024/03/06 12:51:21 by abnaciri		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "pipex.h"

void	ft_put_error(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	exit(1);
}
