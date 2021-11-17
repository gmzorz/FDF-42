/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   height.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 15:49:00 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/18 16:56:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static float	*get_scale(void)
{
	static float	scale = 1.0;

	return (&scale);
}

void	scale_up(t_fdf *scene)
{
	float	*scale;
	size_t	idx;

	idx = 0;
	scale = get_scale();
	*scale += 1;
	while (idx < scene->num_vertices)
	{
		scene->vertices[idx].origin[Y] = scene->vertices[idx].height * (*scale);
		idx += 1;
	}
}

void	scale_down(t_fdf *scene)
{
	float	*scale;
	size_t	idx;

	idx = 0;
	scale = get_scale();
	*scale -= 1;
	while (idx < scene->num_vertices)
	{
		scene->vertices[idx].origin[Y] = scene->vertices[idx].height * (*scale);
		idx += 1;
	}
}
