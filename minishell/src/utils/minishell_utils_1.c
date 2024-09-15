/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:43:03 by skhastag          #+#    #+#             */
/*   Updated: 2024/06/16 03:25:36 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_pwd_from_getcwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (ft_strdup(""));
	return (pwd);
}

char	*get_home_from_getcwd(void)
{
	char	*home;
	char	*pwd;
	char	**tmp;
	char	*tmp2;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (ft_strdup(""));
	tmp = ft_split(pwd, '/');
	tmp2 = ft_strdup("/");
	home = ft_strjoin(tmp2, tmp[0]);
	free(tmp2);
	tmp2 = ft_strjoin(home, "/");
	free(home);
	home = ft_strjoin(tmp2, tmp[1]);
	null_check_free_str(tmp2);
	free_2d(tmp);
	if (home == NULL)
		return (null_check_free_str(pwd), ft_strdup(""));
	null_check_free_str(pwd);
	return (home);
}
