/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/07 11:39:56 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 13:29:24 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

static void	draw_face(
	t_vec *framebuffer,
	const t_face face,
	const PROJECTION projection,
	const DISPLAYMODE display_mode)
{
	if (display_mode != DISPLAY_VERTICALS)
		draw_line(framebuffer,
			(t_vec[2]){face.vertex[0]->raster, face.vertex[1]->raster},
			(t_vec[2]){face.vertex[0]->basecolor, face.vertex[1]->basecolor},
			projection);
	if (display_mode == DISPLAY_HORIZONTALS)
		return ;
	draw_line(framebuffer,
		(t_vec[2]){face.vertex[1]->raster, face.vertex[2]->raster},
		(t_vec[2]){face.vertex[1]->basecolor, face.vertex[2]->basecolor},
		projection);
	if (display_mode == DISPLAY_SQUARES || display_mode == DISPLAY_VERTICALS)
		return ;
	draw_line(framebuffer,
		(t_vec[2]){face.vertex[2]->raster, face.vertex[0]->raster},
		(t_vec[2]){face.vertex[2]->basecolor, face.vertex[0]->basecolor},
		projection);
}

static t_vec	height_to_hsv(float value)
{
	t_vec	rgb;

	rgb[R] = fabs(value * 6.0f - 3.0f) - 1.0f;
	rgb[G] = 2.0f - fabs(value * 6.0f - 2.0f);
	rgb[B] = 2.0f - fabs(value * 6.0f - 4.0f);
	saturate(&rgb);
	return (rgb);
}

static void	get_vertex_colors(
	const float height_max,
	const float height_min,
	const COLORVISUAL color_type,
	t_face face)
{
	uint32_t	idx;
	float		color;

	idx = 0;
	while (idx < 3)
	{
		if (color_type == COLOR_WHITE)
			face.vertex[idx]->basecolor = face.vertex[idx]->color;
		else
			color = (face.vertex[idx]->origin[Y] - height_max)
				/ (height_min - height_max)
				+ (float)(height_min - height_max <= EPSILON);
		if (color != color)
			color = 0.75f;
		if (color_type == COLOR_HEIGHT_GREYSCALE)
			face.vertex[idx]->basecolor = (t_vec){color, color, color, 0.0};
		else if (color_type == COLOR_HEIGHT_HSV)
			face.vertex[idx]->basecolor = height_to_hsv(color);
		idx += 1;
	}
}

void	draw(t_fdf *scene)
{
	uint32_t	face_id;
	t_fragment	frag;

	face_id = 0;
	world_to_camera(scene->vertices, scene->num_vertices, scene);
	camera_to_raster(scene->vertices, scene->num_vertices, scene->projection);
	while (face_id < scene->num_faces)
	{
		if (face_is_visible(scene->faces[face_id], &frag))
		{
			get_vertex_colors(scene->max_bounds[Y],
				scene->min_bounds[Y],
				scene->wire_color,
				scene->faces[face_id]);
			draw_face(scene->framebuffer,
				scene->faces[face_id],
				scene->projection,
				scene->wire_display);
		}
		face_id += 1;
	}
	present(scene);
}
