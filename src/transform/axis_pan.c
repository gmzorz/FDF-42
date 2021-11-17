/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   axis_pan.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 15:32:12 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/21 15:40:09 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

/*
**	Pan (or rotate) a matrix about the identity X axis (1, 0, 0)
*/
void	axis_pan_about_x(t_mat matrix, const float angle)
{
	float	sine;
	float	cosine;
	float	one_minus_cosine;

	sine = sin(angle);
	cosine = cos(angle);
	one_minus_cosine = 1.0f - cosine;
	matrix[0] = (t_vec){one_minus_cosine + cosine, 0.0, 0.0, 0.0};
	matrix[1] = (t_vec){0.0, cosine, sine, 0.0};
	matrix[2] = (t_vec){0.0, -sine, cosine, 0.0};
	matrix[3] = (t_vec){0.0, 0.0, 0.0, 1.0};
}

void	axis_pan_about_y(t_mat matrix, const float angle)
{
	float	sine;
	float	cosine;
	float	one_minus_cosine;

	sine = sin(angle);
	cosine = cos(angle);
	one_minus_cosine = 1.0f - cosine;
	matrix[0] = (t_vec){cosine, sine, -sine, 0.0};
	matrix[1] = (t_vec){0.0, one_minus_cosine + cosine, 0.0, 0.0};
	matrix[2] = (t_vec){sine, 0.0, cosine, 0.0};
	matrix[3] = (t_vec){0.0, 0.0, 0.0, 1.0};
}

/*
**	Pan (or rotate) a matrix about the given axis
*/
void	axis_pan(t_mat matrix, const float angle, const t_vec axis)
{
	float	sine;
	float	cosine;
	float	one_minus_cosine;

	sine = sin(angle);
	cosine = cos(angle);
	one_minus_cosine = 1.0f - cosine;
	matrix[0] = (t_vec){
		one_minus_cosine * axis[X] * axis[X] + cosine,
		one_minus_cosine * axis[X] * axis[Y] + axis[Z] * sine,
		one_minus_cosine * axis[Z] * axis[X] - axis[Y] * sine,
		0.0};
	matrix[1] = (t_vec){
		one_minus_cosine * axis[X] * axis[Y] - axis[Z] * sine,
		one_minus_cosine * axis[Y] * axis[Y] + cosine,
		one_minus_cosine * axis[Y] * axis[Z] + axis[X] * sine,
		0.0};
	matrix[2] = (t_vec){
		one_minus_cosine * axis[Z] * axis[X] + axis[Y] * sine,
		one_minus_cosine * axis[Y] * axis[Z] - axis[X] * sine,
		one_minus_cosine * axis[Z] * axis[Z] + cosine,
		0.0};
	matrix[3] = (t_vec){0.0, 0.0, 0.0, 1.0};
}
