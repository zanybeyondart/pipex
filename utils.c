/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:37:52 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/30 02:21:02 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (counter);
}

char	*ft_add_word(char const *s, int start, int end)
{
	int		i;
	char	*word;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		var[3];
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	while (s[var[0]] != '\0')
	{
		if (s[var[0]] != c)
		{
			var[2] = var[0];
			while (s[var[0]] != c && s[var[0]] != '\0')
				var[0]++;
			result[var[1]++] = ft_add_word(s, var[2], var[0]);
		}
		else
			var[0]++;
	}
	result[var[1]] = NULL;
	return (result);
}

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		free(cmd[i++]);
	free(cmd);
}

char	**set_args(char *path, char *argument)
{
	char	*temp;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(argument, ' ');
	temp = cmd[0];
	cmd[0] = path;
	free(temp);
	return (cmd);
}
