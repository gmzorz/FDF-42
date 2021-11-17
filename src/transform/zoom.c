/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 15:09:04 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:43 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
**	globals xdddddddd
*/
static float	*zoom_get_scale(void)
{
	static float	scale = 1.0;

	return (&scale);
}

void	zoom_in(t_fdf *scene)
{
	float	*scale;

	scale = zoom_get_scale();
	*scale /= 1.1;
	if (scene->projection == PROJECTION_ISOMETRIC)
	{
		scene->isometric[0][X] = scene->geo_size / *scale;
		scene->isometric[1][Y] = scene->geo_size / *scale;
	}
}

void	zoom_out(t_fdf *scene)
{
	float	*scale;

	scale = zoom_get_scale();
	if (*scale >= EPSILON)
		*scale *= 1.1;
	if (scene->projection == PROJECTION_ISOMETRIC)
	{
		scene->isometric[0][X] = scene->geo_size / *scale;
		scene->isometric[1][Y] = scene->geo_size / *scale;
	}
}
