/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:02:08 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/22 04:34:29 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../library/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct pipex
{
	int		pids[2];
	int		fd_pid[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**first_cmd_args;
	char	*first_cmd;
	char	**second_cmd_args;
	char	*second_cmd;
}			t_pipex_data;

int			main(int argc, char *argv[], char *env[]);
void		init_pipex_data(int argc, char *argv[], char *env[],
				t_pipex_data *data);
char		*find_path(char *env[]);
void		first_thread(t_pipex_data *data, char *env[]);
void		second_thread(t_pipex_data *data, char *env[]);
char		*join_cmd(char **paths, char *cmd);
void		perror_free_exit(t_pipex_data *data, char *str, int err_num);
void		perror_exit(char *str, int err_num);
void		close_all(t_pipex_data *data);
void		remove_single_quote(char *str);
void		remove_single_quote_awk(t_pipex_data *data);

#endif
