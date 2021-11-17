/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 14:14:41 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 13:22:29 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H
# define X		0
# define FW		0
# define Y		1
# define UP		1
# define Z		2
# define RT		2
# define W		3
# define U		0
# define V		1

typedef float		t_vec __attribute__ ((vector_size (16)));
typedef t_vec		t_mat[4];
typedef t_vec		t_vec_condition;

float	length(const t_vec vector);
void	normalize(t_vec *vector);
t_vec	normalized(const t_vec vector);
t_vec	saturated(const t_vec vector);
void	saturate(t_vec *vector);
void	vclamp(t_vec *vector, const t_vec min, const t_vec max);
float	clampf(float number, const float min, const float max);
void	clamp(t_vec *vector, const float min, const float max);
t_vec	clamped(t_vec vector, const float min, const float max);
double	dot_product(const t_vec one, const t_vec two);
t_vec	vmin(const t_vec one, const t_vec two);
t_vec	vmax(const t_vec one, const t_vec two);

/*
**	matrix
*/

void	mmul(t_mat dst, const t_mat src);
t_vec	vmul(const t_mat matrix, const t_vec vector);
t_vec	dmul(const t_mat matrix, const t_vec vector);
void	mat_identity(t_mat *mat);
void	mat_transpose(t_mat matrix);

#endif
