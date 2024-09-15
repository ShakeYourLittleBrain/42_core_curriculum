/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:58:28 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/11 19:25:46 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

#define SIZE 4

void	print_matrix(float **matrix, int row, int column)
{
	int	i;
	int	j;

	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < column)
		{
			printf("%f ", matrix[i][j]);
		}
		printf("\n");
	}
}

void	free_matrix(float **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

float	**create_matrix(int row, int column)
{
	float	**matrix;
	int		i;

	matrix = malloc(row * sizeof(float *));
	if (matrix == NULL)
		throw_error_exit("Malloc fail: matrix_utils: line 54", NULL, 1);
	i = -1;
	while (++i < row)
	{
		matrix[i] = malloc(column * sizeof(float));
		if (matrix[i] == NULL)
			throw_error_exit("Malloc fail: matrix_utils: line 60", NULL, 1);
	}
	return (matrix);
}
