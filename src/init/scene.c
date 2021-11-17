/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 15:38:56 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 15:24:59 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <error.h>
#include <libft.h>

t_fdf	*scene_alloc(void)
{
	t_fdf	*scene;

	scene = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	return (scene);
}

/*
**	Default transformation 
*/
void	set_transform(t_fdf *scene)
{
	float	distance;
	t_mat	pan[2];

	scene->geo_size = fmax(scene->width, scene->height);
	scene->geo_size = fmax(scene->geo_size, -scene->max_bounds[Y] / 100);
	scene->geo_size = -10.f / scene->geo_size;
	distance = -sqrtf(-scene->max_bounds[Z] * -scene->max_bounds[Z]
			+ -scene->max_bounds[X] * -scene->max_bounds[X]);
	scene->transform[3] = (t_vec){distance, distance, distance, 1.0};
	axis_pan(pan[0], -45, scene->transform[Y]);
	axis_pan_about_x(pan[1], 32);
	mmul(pan[0], pan[1]);
	mmul(scene->transform, pan[0]);
	scene->isometric[0] = (t_vec){scene->geo_size, 0.0, 0.0, 0.0};
	scene->isometric[1] = (t_vec){0.0, scene->geo_size, 0.0, 0.0};
	scene->isometric[2] = (t_vec){0.0, 0.0, -1.0, 0.0};
	scene->isometric[3] = (t_vec){RES_W / 2.f, RES_H / 2.f, 0.0, 1.0};
	scene->rotation[0] = (t_vec){-0.707, -0.408, -0.577, 0.000};
	scene->rotation[1] = (t_vec){-0.000, 0.816, -0.577, 0.000};
	scene->rotation[2] = (t_vec){0.707, -0.408, -0.577, 0.000};
	scene->rotation[3] = (t_vec){0.000, 0.000, 0.000, 1.000};
}

bool	scene_init(t_fdf *scene, const char *file)
{
	setup_mlx(&scene->buffer);
	setup_hook(scene);
	scene->framebuffer = init_framebuffer();
	if (scene->framebuffer == NULL)
		return (false);
	if (ft_matchend(file, ".xpm"))
	{
		if (!parse_image(scene, file))
			return (error_msg(ERR_PARSE));
	}
	else
	{
		if (!verify_map(scene, file))
			return (error_msg(ERR_PARSE));
		if (!parse_map(scene, file))
			return (error_msg(ERR_PARSE));
	}
	mat_identity(&scene->transform);
	mat_identity(&scene->isometric);
	mat_identity(&scene->rotation);
	set_transform(scene);
	return (true);
}
