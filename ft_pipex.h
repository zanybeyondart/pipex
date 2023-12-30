/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:23:17 by zvakil            #+#    #+#             */
/*   Updated: 2023/11/30 02:01:50 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <strings.h>

void	free_args(char **temp);
char	**set_args(char *path, char *argument);
void	checks(int ac, char **av);
char	**ft_split(char const *s, char c);
void	free_cmd(char **cmd);
char	*set_path(char *path, char *cmd);

#endif