/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:00:23 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:36 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <vec.h>

void	move_right(t_fdf *scene)
{
	const static t_vec	movement = (t_vec){
		MOVE_SPEED, 0.0, 0.0, 0.0
	};

	scene->transform[3] += movement * scene->camera_speedscale;
}

void	move_left(t_fdf *scene)
{
	const static t_vec	movement = (t_vec){
		MOVE_SPEED, 0.0, 0.0, 0.0
	};

	scene->transform[3] -= movement * scene->camera_speedscale;
}
