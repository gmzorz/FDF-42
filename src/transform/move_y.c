/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_y.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:12:52 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:39 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <vec.h>

void	move_up(t_fdf *scene)
{
	const static t_vec	movement = (t_vec){
		0.0, MOVE_SPEED, 0.0, 0.0
	};

	scene->transform[3] += movement * scene->camera_speedscale;
}

void	move_down(t_fdf *scene)
{
	const static t_vec	movement = (t_vec){
		0.0, MOVE_SPEED, 0.0, 0.0
	};

	scene->transform[3] -= movement * scene->camera_speedscale;
}
