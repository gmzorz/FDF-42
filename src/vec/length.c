/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   length.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 14:16:49 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/06 17:29:33 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>
#include <math.h>

float	length(const t_vec vector)
{
	return (sqrtf(vector[X] * vector[X]
			+ vector[Y] * vector[Y]
			+ vector[Z] * vector[Z]
			+ vector[W] * vector[W]));
}
