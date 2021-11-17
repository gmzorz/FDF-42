/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mul.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 11:50:25 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/18 09:53:41 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <stdint.h>
#include <libft.h>

/*
**	Multiply a vector by a given matrix
**	Vector (directional) multiplication ONLY, similar to vmul
*/
t_vec	dmul(const t_mat matrix, const t_vec vector)
{
	return ((t_vec){vector[X] * matrix[0][X]
		+ vector[Y] * matrix[1][X]
		+ vector[Z] * matrix[2][X],
		vector[X] * matrix[0][Y]
		+ vector[Y] * matrix[1][Y]
		+ vector[Z] * matrix[2][Y],
		vector[X] * matrix[0][Z]
		+ vector[Y] * matrix[1][Z]
		+ vector[Z] * matrix[2][Z],
		0.0});
}

/*
**	Multiply a point (or a vector) by a given matrix
*/
t_vec	vmul(const t_mat matrix, const t_vec vector)
{
	t_vec	outvec;

	outvec[X] = vector[X] * matrix[0][X]
		+ vector[Y] * matrix[1][X]
		+ vector[Z] * matrix[2][X]
		+ matrix[3][X];
	outvec[Y] = vector[X] * matrix[0][Y]
		+ vector[Y] * matrix[1][Y]
		+ vector[Z] * matrix[2][Y]
		+ matrix[3][Y];
	outvec[Z] = vector[X] * matrix[0][Z]
		+ vector[Y] * matrix[1][Z]
		+ vector[Z] * matrix[2][Z]
		+ matrix[3][Z];
	outvec[W] = vector[X] * matrix[0][W]
		+ vector[Y] * matrix[1][W]
		+ vector[Z] * matrix[2][W]
		+ matrix[3][W];
	outvec /= outvec[W];
	outvec[W] = 0.0f;
	return (outvec);
}

/*
**	Multiply matrix by given matrix
*/
void	mmul(t_mat dst, const t_mat src)
{
	t_mat		out;
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out[i][j] = dst[i][0] * src[0][j]
				+ dst[i][1] * src[1][j]
				+ dst[i][2] * src[2][j]
				+ dst[i][3] * src[3][j];
			j += 1;
		}
		i += 1;
	}
	ft_memcpy(dst, out, sizeof(t_mat));
}
