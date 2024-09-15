/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:38:00 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/11 22:35:42 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	free_argv(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next_node;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (!*argv[1] || !input_error(argc, argv))
		return (write(1, "Error\n", 6), 1);
	if (argc == 2)
		init_stack_a(&a, ft_split(argv[1], ' '), 1);
	else
		init_stack_a(&a, argv + 1, 0);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			swap_a(&a);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
