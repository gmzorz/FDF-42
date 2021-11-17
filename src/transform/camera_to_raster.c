/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_to_raster.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/07 13:30:52 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:07:45 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <vec.h>
#include <math.h>

static void	single_camera_to_raster(
	t_vertex *vertex,
	const PROJECTION projection)
{
	t_vec	screen;

	screen[X] = vertex->camera[X];
	screen[Y] = vertex->camera[Y];
	if (projection == PROJECTION_PERSPECTIVE)
	{
		screen /= -vertex->camera[Z];
		vertex->raster[X] = (screen[X] + 1) / 2 * RES_W;
		vertex->raster[Y] = (1 - screen[Y]) / 2 * RES_H;
	}
	else
		vertex->raster = screen;
	vertex->raster[Z] = 1 / -vertex->camera[Z];
}

void	camera_to_raster(
	t_vertex *vertices,
	const size_t num_vertices,
	const PROJECTION projection)
{
	size_t	idx;

	idx = 0;
	while (idx < num_vertices)
	{
		single_camera_to_raster(&vertices[idx], projection);
		idx += 1;
	}
}
