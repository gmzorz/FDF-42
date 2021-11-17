/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_z.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:13:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:41 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <vec.h>

void	move_forward(t_fdf *scene)
{
	const static t_vec	movement = (t_vec){
		0.0, 0.0, MOVE_SPEED, 0.0
	};

	scene->transform[3] += movement * scene->camera_speedscale;
}

void	move_back(t_fdf *scene)
{
	const static t_vec	movement = (t_vec){
		0.0, 0.0, MOVE_SPEED, 0.0
	};

	scene->transform[3] -= movement * scene->camera_speedscale;
}
