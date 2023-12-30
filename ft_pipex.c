/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:22:33 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/30 02:23:01 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	child_process(char *path, char **args, char **av, int ac)
{
	int		p[2];
	int		file;
	char	*str;

	pipe(p);
	if (fork() == 0)
	{
		dup2(p[1], 1);
		close(p[0]);
		execve(path, args, NULL);
	}
	wait(NULL);
	file = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	close(p[1]);
	dup2(file, 1);
	while (1)
	{
		str = get_next_line(p[0]);
		if (!str)
			break ;
		printf("%s", str);
		free(str);
	}
	close(file);
	exit(1);
}

char	*cmd_name(char *cmd)
{
	char	*temp;
	int		i;

	i = 0;
	while (cmd[i] != '\0' && cmd[i] != ' ')
		i++;
	temp = malloc(i + 1);
	i = 0;
	while (cmd[i] != '\0' && cmd[i] != ' ')
	{
		temp[i] = cmd[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*set_command_path(char *command, int ac, char **av)
{
	char	*path;
	char	*cmd;

	cmd = cmd_name(command);
	path = set_path("/bin/", cmd);
	if (access(path, F_OK) == 0)
	{
		free(cmd);
		return (path);
	}
	free(path);
	path = set_path("/usr/bin/", cmd);
	if (access(path, F_OK) == 0)
	{
		free(cmd);
		return (path);
	}
	free(path);
	free(cmd);
	open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	printf("Invalid Command : %s\n", command);
	exit(1);
}

int	main(int ac, char **av)
{
	char	**args;
	int		i;
	int		file;
	char	*path;

	i = 2;
	// checks(ac, av);
	while (i < ac - 1)
	{
		path = set_command_path(av[i], ac, av);
		args = set_args(path, av[i]);
		if (i == 2)
			file = open(av[1], O_RDONLY);
		else
			file = open(av[ac - 1], O_RDONLY);
		dup2(file, 0);
		if (fork() == 0)
			child_process(args[0], args, av, ac);
		wait(NULL);
		free_cmd(args);
		close(file);
		i++;
	}
	return (0);
}
