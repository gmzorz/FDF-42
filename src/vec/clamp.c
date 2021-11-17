/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clamp.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 12:47:14 by goosterl      #+#    #+#                 */
/*   Updated: 2021/11/17 10:38:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

void	vclamp(t_vec *vector, const t_vec min, const t_vec max)
{
	t_vec_condition	is_higher;
	t_vec_condition	is_lower;

	is_higher = -__builtin_convertvector(*vector > max, t_vec_condition);
	is_lower = -__builtin_convertvector(*vector < min, t_vec_condition);
	*vector = *vector - *vector * is_higher + is_higher * max;
	*vector = *vector - *vector * is_lower + is_lower * min;
}

t_vec	clamped(t_vec vector, const float min, const float max)
{
	t_vec	clamped;

	clamped = vector;
	clamp(&clamped, min, max);
	return (clamped);
}

void	clamp(t_vec *vector, const float min, const float max)
{
	t_vec			upper;
	t_vec			lower;
	t_vec_condition	is_higher;
	t_vec_condition	is_lower;

	upper = (t_vec){max, max, max, max};
	lower = (t_vec){min, min, min, min};
	is_higher = -__builtin_convertvector(*vector > upper, t_vec_condition);
	is_lower = -__builtin_convertvector(*vector < lower, t_vec_condition);
	*vector = *vector - *vector * is_higher + is_higher * max;
	*vector = *vector - *vector * is_lower + is_lower * min;
}

float	clampf(float number, const float min, const float max)
{
	return (number * (number > min && number < max)
		+ max * (number > max) + min * (number < min));
}
