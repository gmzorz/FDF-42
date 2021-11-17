/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   world_to_camera.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 13:24:03 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 13:40:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
**	Convert vertices from world to camera space using a given 
**	transformation matrix.
*/
void	world_to_camera(
	t_vertex *vertices,
	const size_t num_vertices,
	t_fdf *scene)
{
	size_t	idx;

	idx = 0;
	scene->min_bounds = (t_vec){0, 0, 0, 0};
	scene->max_bounds = (t_vec){0, 0, 0, 0};
	while (idx < num_vertices)
	{
		if (scene->projection == PROJECTION_ISOMETRIC)
		{
			vertices[idx].camera = vmul(scene->rotation, vertices[idx].origin);
			vertices[idx].camera = vmul(scene->isometric, vertices[idx].camera);
		}
		else
			vertices[idx].camera = vmul(scene->transform, vertices[idx].origin);
		scene->min_bounds = vmax(vertices[idx].origin, scene->min_bounds);
		scene->max_bounds = vmin(vertices[idx].origin, scene->max_bounds);
		idx += 1;
	}
}
