/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:26:15 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/11 21:39:07 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

float	**invert_matrix(float **a)
{
	float	**cofactor;
	float	**transpose;
	float	**inverse;

	transpose = create_matrix(4, 4);
	inverse = create_matrix(4, 4);
	cofactor = matrix_cofactor(a, 0, 0);
	transpose = transpose_matrix(cofactor);
	inverse = matrix_devision_1m(transpose, determinant_4(a));
	free_matrix(transpose, 4);
	free_matrix(cofactor, 4);
	return (inverse);
}

float	**matrix_cofactor(float **a, int i, int j)
{
	float	**co_matrix;
	float	**temp;
	int		point[2];

	co_matrix = create_matrix(4, 4);
	i = -1;
	while (++i < MATRIX_SIZE)
	{
		j = -1;
		while (++j < MATRIX_SIZE)
		{
			point[0] = i;
			point[1] = j;
			temp = submatrix(a, point, 4, -1);
			if ((j % 2 == 1 && i % 2 == 0) || (j % 2 == 0 && i % 2 == 1))
				co_matrix[i][j] = determinant_3(temp) * -1;
			else
				co_matrix[i][j] = determinant_3(temp);
			free_matrix(temp, 3);
		}
	}
	return (co_matrix);
}

float	**matrix_devision_1m(float **a, float devisor)
{
	float	**result;

	result = create_matrix(MATRIX_SIZE, MATRIX_SIZE);
	result[0][0] = a[0][0] / devisor;
	result[1][0] = a[1][0] / devisor;
	result[2][0] = a[2][0] / devisor;
	result[3][0] = a[3][0] / devisor;
	result[0][1] = a[0][1] / devisor;
	result[1][1] = a[1][1] / devisor;
	result[2][1] = a[2][1] / devisor;
	result[3][1] = a[3][1] / devisor;
	result[0][2] = a[0][2] / devisor;
	result[1][2] = a[1][2] / devisor;
	result[2][2] = a[2][2] / devisor;
	result[3][2] = a[3][2] / devisor;
	result[0][3] = a[0][3] / devisor;
	result[1][3] = a[1][3] / devisor;
	result[2][3] = a[2][3] / devisor;
	result[3][3] = a[3][3] / devisor;
	return (result);
}

float	**transpose_matrix(float **a)
{
	float	**result;

	result = create_matrix(MATRIX_SIZE, MATRIX_SIZE);
	result[0][0] = a[0][0];
	result[0][1] = a[1][0];
	result[0][2] = a[2][0];
	result[0][3] = a[3][0];
	result[1][0] = a[0][1];
	result[1][1] = a[1][1];
	result[1][2] = a[2][1];
	result[1][3] = a[3][1];
	result[2][0] = a[0][2];
	result[2][1] = a[1][2];
	result[2][2] = a[2][2];
	result[2][3] = a[3][2];
	result[3][0] = a[0][3];
	result[3][1] = a[1][3];
	result[3][2] = a[2][3];
	result[3][3] = a[3][3];
	return (result);
}

float	determinant_4(float **a)
{
	float	result[4];
	int		point[2];
	float	**temp;
	int		i;

	i = -1;
	while (++i < MATRIX_SIZE)
	{
		point[0] = i;
		point[1] = 0;
		temp = submatrix(a, point, 4, -1);
		result[i] = determinant_3(temp);
		free_matrix(temp, 3);
	}
	return (a[0][0] * result[0] - a[1][0] * result[1] + a[2][0] * result[2]
		- a[3][0] * result[3]);
}
