/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 02:21:04 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/30 02:21:16 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	checks(int ac, char **av)
{
	if (ac != 5)
	{
		printf("Invalid Agruments : file1 cmd1 cmd2 file2\n");
		exit (0);
	}
	if (access(av[1], R_OK) < 0)
	{
		printf("Invalid file : %s\n", av[1]);
		exit (0);
	}
}

char *set_path(char *path, char *cmd)
{
	char	*final;
	int		i;
	int		j;

	i = 0;
	j = 0;
	final = malloc(strlen(path) + strlen(cmd) + 1);
	while (path[i] != '\0')
	{
		final[i] = path[i];
		i++;
	}
	while (cmd[j] != '\0')
		final[i++] = cmd[j++];
	final[i] = '\0';
	return (final);
}