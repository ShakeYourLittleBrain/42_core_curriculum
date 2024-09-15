/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:54:23 by mohrahma          #+#    #+#             */
/*   Updated: 2024/06/17 00:31:34 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	buildin_manager_check(t_minishell_data *mini)
{
	if (ft_strncmp(mini->cmds->args[0], "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(mini->cmds->args[0], "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(mini->cmds->args[0], "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(mini->cmds->args[0], "env", 4) == 0)
		return (1);
	else if (ft_strncmp(mini->cmds->args[0], "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(mini->cmds->args[0], "export", 7) == 0)
		return (1);
	return (0);
}

void	buildin_manager(t_minishell_data *mini)
{
	if (ft_strncmp(mini->cmds->args[0], "cd", \
		ft_strlen(mini->cmds->args[0])) == 0)
		ft_cd(mini);
	else if (ft_strncmp(mini->cmds->args[0], "pwd", \
		ft_strlen(mini->cmds->args[0])) == 0)
		ft_pwd(mini);
	else if (ft_strncmp(mini->cmds->args[0], "echo", \
		ft_strlen(mini->cmds->args[0])) == 0)
		ft_echo(mini, 1);
	else if (ft_strncmp(mini->cmds->args[0], "env", \
		ft_strlen(mini->cmds->args[0])) == 0)
		ft_env(mini);
	else if (ft_strncmp(mini->cmds->args[0], "unset", \
		ft_strlen(mini->cmds->args[0])) == 0)
		ft_unset(mini);
	else if (ft_strncmp(mini->cmds->args[0], "export", \
		ft_strlen(mini->cmds->args[0])) == 0)
		ft_export(mini);
}
