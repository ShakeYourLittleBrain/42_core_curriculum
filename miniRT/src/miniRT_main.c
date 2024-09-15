/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 03:14:19 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/10 03:22:29 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*.....https://trello.com/invite/b/668abec2f8d5da5097f8db03/
					ATTI8ae9e10732d027ded847cd2833946d4b2B7061C7/42-minirt....*/
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_miniRT	*mini_rt;

	(void)envp;
	input_validation(argc, argv);
	init_minirt(&mini_rt);
	prep_scene(&mini_rt, argv[1]);
	if (DEBUG)
		print_objects(mini_rt->objects_head);
	printf(INSTRUCTIONS);
	prep_window(&mini_rt);
	return (ft_gc_free(get_gc()), EXIT_SUCCESS);
}
