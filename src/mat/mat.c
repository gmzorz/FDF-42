/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 12:48:43 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 15:29:26 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <vec.h>

void	mat_identity(t_mat *mat)
{
	const t_mat	identity = {
		(t_vec){1.0, 0.0, 0.0, 0.0},
		(t_vec){0.0, 1.0, 0.0, 0.0},
		(t_vec){0.0, 0.0, 1.0, 0.0},
		(t_vec){0.0, 0.0, 0.0, 1.0}
	};

	(*mat)[0] = identity[0];
	(*mat)[1] = identity[1];
	(*mat)[2] = identity[2];
	(*mat)[3] = identity[3];
}
