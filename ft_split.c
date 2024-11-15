/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:06:12 by abnaciri          #+#    #+#             */
/*   Updated: 2024/05/01 20:04:10 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	cntword(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else
			i++;
	}
	return (cnt);
}

static char	*allocword(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	word = malloc((i + 1) * sizeof(char));
	if (!word)
	{
		return (0);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i--]);
	}
	free(res);
	return (0);
}

char	**check_grep(char **res)
{
	int	j;

	j = 2;
	if (handle_grep(*res))
	{
		if (res[1] != NULL && res[1][0] == 39)
		{
			if (res[1][1] == 39 && res[1][2] == '\0')
				res[1] = " ";
			else if ((res[1][1] <= 32 && res[1][2] == 39) || res[1][1] == '\0')
				res[1] = " ";
			else if (res[1][1] == 39 && res[1][2] == 39 && res[1][1] == 39)
				res[1] = "'";
			while (res[j] != NULL)
			{
				res[j] = NULL;
				j++;
			}
		}
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;

	if (!s)
		return (0);
	res = (char **)malloc((cntword(s, c) + 1) * sizeof(char *));
	if (!res)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			res[i] = allocword(s, c);
			if (!res[i])
				return (ft_free(res, i--));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = NULL;
	return (check_grep(res));
}
