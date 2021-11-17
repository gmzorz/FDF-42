/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 12:49:42 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:34 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

/*
**	Scales the vertical delta (velocity) based on angle
**	The angular velocity will decrease when nearing the polars (UP/DOWN)
**	and will speed back up when a different direction is triggered
*/
double	vertical_scalar(const t_mat world_transform, const float delta_y)
{
	double			tangent;

	tangent = tan(world_transform[Y][Y]) / M_PI_2;
	if (world_transform[Y][Z] < 0 && delta_y > 0)
		return (delta_y);
	else if (world_transform[Y][Z] > 0 && delta_y < 0)
		return (delta_y);
	return (delta_y * tangent);
}

/*
**	Rotate (or pan) camera about two axes, the first one being the UP
**	vector of the world transform, the second one being a static vector
*/
void	pan_camera(const int32_t delta_x, const int32_t delta_y, t_fdf *scene)
{
	t_mat		pan_x;
	t_mat		pan_y;
	t_mat		vertical_check;
	float		delta[2];

	ft_memcpy(vertical_check, scene->transform, sizeof(t_mat));
	delta[X] = (float)delta_x * PI_DELTA;
	delta[Y] = vertical_scalar(scene->transform, (float)delta_y * PI_DELTA);
	axis_pan(pan_x, delta[X], scene->transform[Y]);
	axis_pan_about_x(pan_y, delta[Y]);
	mmul(vertical_check, pan_y);
	mat_transpose(vertical_check);
	if (vertical_check[Y][Y] > EPSILON)
		mmul(pan_x, pan_y);
	mmul(scene->transform, pan_x);
	normalize(&scene->transform[0]);
	normalize(&scene->transform[1]);
	normalize(&scene->transform[2]);
}
