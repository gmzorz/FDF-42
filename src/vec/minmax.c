/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minmax.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 15:37:29 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/08 15:53:38 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

t_vec	vmin(const t_vec one, const t_vec two)
{
	t_vec_condition	is_higher;

	is_higher = -__builtin_convertvector(one < two, t_vec_condition);
	return (two * ((is_higher - 1.f) * -1.f) + one * is_higher);
}

t_vec	vmax(const t_vec one, const t_vec two)
{
	t_vec_condition	is_lower;

	is_lower = -__builtin_convertvector(one > two, t_vec_condition);
	return (two * ((is_lower - 1.f) * -1.f) + one * is_lower);
}
