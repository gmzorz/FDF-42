/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dot.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 15:12:06 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/06 17:29:04 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

double	dot_product(const t_vec one, const t_vec two)
{
	return (one[X] * two[X] + one[Y] * two[Y] + one[Z] * two[Z]);
}
