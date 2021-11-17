/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 14:36:07 by goosterl      #+#    #+#                 */
/*   Updated: 2021/06/21 14:33:32 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

void	normalize(t_vec *vector)
{
	*vector /= length(*vector);
}

t_vec	normalized(t_vec vector)
{
	return (vector / length(vector));
}
