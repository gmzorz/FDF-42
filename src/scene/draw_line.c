/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 13:25:40 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 12:03:42 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <buffer.h>

static void	set_pixel(
	const int32_t points[][2],
	t_vec *framebuffer,
	const t_vec color)
{
	uint32_t	pixel_idx;

	if (points[0][X] > 0
		&& points[0][X] < RES_W
		&& points[0][Y] > 0
		&& points[0][Y] < RES_H)
	{
		pixel_idx = points[0][Y] * RES_H + points[0][X];
		if ((framebuffer[pixel_idx])[W] > color[W])
			framebuffer[pixel_idx] = color;
	}
}

static int32_t	maxi(int32_t one, int32_t two)
{
	return ((one < two) * two + (one > two) * one + (one == two) * one);
}

/*
**	bresenham edgecase: 45 degree lines
*/
static void	bresenham_45(
	t_vec *framebuffer,
	int32_t pos[][2],
	int32_t	delta[2],
	t_vec	color[2])
{
	t_vec	color_lerp;

	color_lerp = (color[1] - color[0]);
	color_lerp /= (float)(maxi(abs(delta[0]), abs(delta[1])) >> 1);
	while (pos[0][X] != pos[1][X])
	{
		set_pixel(pos, framebuffer, color[0]);
		pos[0][X] += ((delta[X] > 0) << 1) - 1;
		pos[0][Y] += ((delta[Y] > 0) << 1) - 1;
		color[0] += color_lerp;
	}
	set_pixel(pos, framebuffer, color[0]);
}

static void	bresenham(
	t_vec *framebuffer,
	int32_t pos[][2],
	int32_t	delta[2],
	t_vec	color[2])
{
	int32_t	*step;
	int32_t	axis;
	int32_t	fraction;
	t_vec	color_lerp;

	step = (int32_t[2]){((delta[X] > 0) << 1) - 1, ((delta[Y] > 0) << 1) - 1};
	delta = (int32_t[2]){(delta[X] * step[X]) << 1, (delta[Y] * step[Y]) << 1};
	axis = delta[X] < delta[Y];
	color_lerp = (color[1] - color[0]);
	color_lerp /= (float)(maxi(abs(delta[0]), abs(delta[1])) >> 1);
	fraction = delta[Y != axis] - (delta[X != axis] >> 1);
	while (pos[0][X != axis] != pos[1][X != axis])
	{
		if (fraction >= 0)
		{
			pos[0][Y != axis] += step[Y != axis];
			fraction -= delta[X != axis];
		}
		pos[0][X != axis] += step[X != axis];
		fraction += delta[Y != axis];
		color[0] += color_lerp;
		set_pixel(pos, framebuffer, color[0]);
	}
}

void	draw_line(
	t_vec *framebuffer,
	const t_vec coords[2],
	const t_vec color[2],
	const PROJECTION projection)
{
	int32_t	points[2][2];
	t_vec	color_and_z[2];
	int32_t	delta[2];

	if (projection == PROJECTION_PERSPECTIVE
		&& (coords[0][Z] <= 0 || coords[1][Z] <= 0))
		return ;
	points[0][0] = ceil(coords[0][X]);
	points[0][1] = ceil(coords[0][Y]);
	points[1][0] = ceil(coords[1][X]);
	points[1][1] = ceil(coords[1][Y]);
	color_and_z[0] = color[0];
	color_and_z[1] = color[1];
	color_and_z[0][W] = 1 / coords[0][Z];
	color_and_z[1][W] = 1 / coords[1][Z];
	delta[X] = points[1][X] - points[0][X];
	delta[Y] = points[1][Y] - points[0][Y];
	if (delta[Y] == delta[X])
		bresenham_45(framebuffer, points, delta, color_and_z);
	else
		bresenham(framebuffer, points, delta, color_and_z);
}
