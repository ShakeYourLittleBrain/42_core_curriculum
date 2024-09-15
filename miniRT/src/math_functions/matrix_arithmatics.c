/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_arithmatics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:20:44 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/11 19:27:51 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

#define SIZE 4

float	**matrix_multiplication_1m(float **a, float multiple)
{
	float	**result;

	result = create_matrix(SIZE, SIZE);
	result[0][0] = a[0][0] * multiple;
	result[1][0] = a[1][0] * multiple;
	result[2][0] = a[2][0] * multiple;
	result[3][0] = a[3][0] * multiple;
	result[0][1] = a[0][1] * multiple;
	result[1][1] = a[1][1] * multiple;
	result[2][1] = a[2][1] * multiple;
	result[3][1] = a[3][1] * multiple;
	result[0][2] = a[0][2] * multiple;
	result[1][2] = a[1][2] * multiple;
	result[2][2] = a[2][2] * multiple;
	result[3][2] = a[3][2] * multiple;
	result[0][3] = a[0][3] * multiple;
	result[1][3] = a[1][3] * multiple;
	result[2][3] = a[2][3] * multiple;
	result[3][3] = a[3][3] * multiple;
	return (result);
}

float	**matrix_multiplication(float **a, float **b)
{
	float	**result;
	int		i;
	int		j;
	int		k;
	int		sum;

	result = create_matrix(SIZE, SIZE);
	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			sum = 0;
			k = -1;
			while (++k < SIZE)
				sum += a[i][k] * b[k][j];
			result[i][j] = sum;
		}
	}
	return (result);
}

float	determinant_3(float **a)
{
	return (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1]
		* (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1]
			- a[1][1] * a[2][0]));
}

float	**submatrix(float **a, int *point, int size, int l)
{
	float	**result;
	int		i;
	int		j;
	int		k;

	result = malloc((size) * sizeof(float *));
	i = -1;
	k = 0;
	while (++i < size)
	{
		if (i == point[0])
			continue ;
		result[k] = malloc((size) * sizeof(float));
		j = -1;
		l = 0;
		while (++j < size)
		{
			if (j == point[1])
				continue ;
			result[k][l] = a[i][j];
			l++;
		}
		k++;
	}
	return (result);
}

float	determinant_4(float **a)
{
	float	result[4];
	int		point[2];
	float	**temp;
	int		i;

	i = -1;
	while (++i < SIZE)
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
