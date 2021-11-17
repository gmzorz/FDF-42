/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   saturate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 14:59:27 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 16:07:40 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_vec	saturated(const t_vec vector)
{
	t_vec	saturated;

	saturated = vector;
	saturate(&saturated);
	return (saturated);
}

void	saturate(t_vec *vector)
{
	const t_vec			upper = (t_vec){1.0, 1.0, 1.0, 1.0};
	const t_vec			lower = (t_vec){0.0, 0.0, 0.0, 0.0};
	t_vec_condition		higher;
	t_vec_condition		in_range;

	higher = -__builtin_convertvector(*vector > upper, t_vec_condition);
	in_range = -__builtin_convertvector(*vector > lower, t_vec_condition);
	*vector = *vector - *vector * higher + higher;
	*vector *= in_range;
}
