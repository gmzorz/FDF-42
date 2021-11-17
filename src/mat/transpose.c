/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transpose.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 16:05:08 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:07 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <stdint.h>

void	mat_transpose(t_mat matrix)
{
	matrix[0][1] += matrix[1][0];
	matrix[1][0] = matrix[0][1] - matrix[1][0];
	matrix[0][1] -= matrix[1][0];
	matrix[0][2] += matrix[2][0];
	matrix[2][0] = matrix[0][2] - matrix[2][0];
	matrix[0][2] -= matrix[2][0];
	matrix[2][1] += matrix[1][2];
	matrix[1][2] = matrix[2][1] - matrix[1][2];
	matrix[2][1] -= matrix[1][2];
}
