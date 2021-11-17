/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_params.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 16:03:05 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 15:59:09 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_scene_parameters(t_fdf *scene)
{
	size_t	idx;

	idx = 0;
	while (idx < scene->num_vertices)
	{
		scene->min_bounds = vmin(scene->min_bounds,
				scene->vertices[idx].origin);
		scene->max_bounds = vmax(scene->max_bounds,
				scene->vertices[idx].origin);
		idx += 1;
	}
}
