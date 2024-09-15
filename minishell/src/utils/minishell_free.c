/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 01:56:21 by skhastag          #+#    #+#             */
/*   Updated: 2024/06/17 03:09:56 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_mini_dto(t_minishell_data *mini_dto)
{
	if (mini_dto)
	{
		if (mini_dto->envp)
			free_2d(mini_dto->envp);
		if (mini_dto->tokens && mini_dto->readline)
			free_token_list(mini_dto->tokens);
		if (mini_dto->cmds && mini_dto->readline)
			free_cmd_list(mini_dto->cmds);
		if (mini_dto->home)
			null_check_free_str(mini_dto->home);
		if (mini_dto->pwd)
			null_check_free_str(mini_dto->pwd);
		if (mini_dto->readline)
			null_check_free_str(mini_dto->readline);
	}
	mini_dto = NULL;
}

void	free_cmd_list(t_ast *cmds)
{
	t_ast	*temp;

	temp = NULL;
	while (cmds)
	{
		temp = cmds;
		if (cmds->args)
			free_2d(cmds->args);
		cmds = cmds->next;
		free(temp);
	}
}

void	null_check_free_str(char *str)
{
	if (str != NULL)
		free(str);
	str = NULL;
}

void	free_2d(char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		return ;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
	args = NULL;
}

void	ft_upd_shelvl_free(t_minishell_data *mini,
		char *old_lvl_num, char *new_lvl_num)
{
	find_and_replace_env(mini->envp, "SHLVL=", old_lvl_num);
	null_check_free_str(new_lvl_num);
	null_check_free_str(old_lvl_num);
}
