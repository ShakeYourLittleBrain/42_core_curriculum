/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:00:55 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/08 22:16:12 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	close_all(t_pipex_data *data)
{
	close(data->infile);
	close(data->outfile);
	close(data->fd_pid[0]);
	close(data->fd_pid[1]);
}

void	first_thread(t_pipex_data *data, char *env[])
{
	dup2(data->fd_pid[1], STDOUT_FILENO);
	dup2(data->infile, STDIN_FILENO);
	close(data->fd_pid[0]);
	if (execve(data->first_cmd, data->first_cmd_args, env) == -1)
		perror_free_exit(data, "Execve failed!", ENOEXEC);
	exit(EXIT_SUCCESS);
}

void	second_thread(t_pipex_data *data, char *env[])
{
	dup2(data->fd_pid[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(data->fd_pid[1]);
	if (execve(data->second_cmd, data->second_cmd_args, env) == -1)
		perror_free_exit(data, "Execve failed!", ENOEXEC);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex_data	data;

	if (argc != 5)
		return (perror("Invalid number of arguments."), 1);
	init_pipex_data(argc, argv, env, &data);
	if (pipe(data.fd_pid) < 0)
		perror_free_exit(&data, "Pipe creation error", 1);
	data.pids[0] = fork();
	if (data.pids[0] == 0)
		first_thread(&data, env);
	data.pids[1] = fork();
	if (data.pids[1] == 0)
		second_thread(&data, env);
	close_all(&data);
	waitpid(data.pids[0], NULL, 0);
	waitpid(data.pids[1], NULL, 0);
	perror_free_exit(&data, NULL, 0);
	return (0);
}
