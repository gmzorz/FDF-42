/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 11:48:10 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 13:38:03 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <error.h>

static void	image_to_vertices(t_mlx *image_buffer, t_vertex *vertices)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	vert_idx;
	float		half_size[2];

	x = 0;
	y = 0;
	half_size[X] = (float)(image_buffer->width - 1) / 2;
	half_size[Y] = (float)(image_buffer->height - 1) / 2;
	while (y < image_buffer->height)
	{
		while (x < image_buffer->width)
		{
			vert_idx = y * image_buffer->width + x;
			vertices[vert_idx].color = get_color_at(image_buffer, vert_idx);
			vertices[vert_idx].origin[X] = 100 * ((float)x - half_size[X]);
			vertices[vert_idx].origin[Z] = 100 * ((float)y - half_size[Y]);
			vertices[vert_idx].origin[Y] = length(vertices[vert_idx].color)
				* 1000;
			vertices[vert_idx].height = vertices[vert_idx].origin[Y];
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

static bool	set_scene_params(t_fdf *scene, t_mlx *image_buffer)
{
	scene->height = image_buffer->height;
	scene->width = image_buffer->width;
	scene->num_vertices = scene->width * scene->height;
	scene->num_faces = (scene->width - 1) * (scene->height - 1) * 2;
	scene->vertices = (t_vertex *)ft_calloc(1,
			sizeof(t_vertex) * scene->num_vertices);
	if (scene->vertices == NULL)
		return (error_msg(ERR_ALLOC_VERT));
	scene->faces = (t_face *)ft_calloc(1, sizeof(t_face) * scene->num_faces);
	if (scene->faces == NULL)
		return (error_msg(ERR_ALLOC_MAP));
	return (true);
}

bool	parse_image(t_fdf *scene, const char *file)
{
	t_mlx	image_buffer;

	image_buffer.image = mlx_xpm_file_to_image(
			scene->buffer.mlx, (char *)file,
			(int *)&image_buffer.width,
			(int *)&image_buffer.height);
	if (image_buffer.image == NULL)
		return (error_msg(ERR_PAR_IMAGE));
	image_buffer.address = mlx_get_data_addr(
			image_buffer.image,
			&image_buffer.bpp,
			&image_buffer.size_line,
			&image_buffer.endian);
	if (set_scene_params(scene, &image_buffer) == false)
		return (false);
	image_to_vertices(&image_buffer, scene->vertices);
	construct_triangles(scene);
	mlx_destroy_image(scene->buffer.mlx, image_buffer.image);
	scene->height_from_image = true;
	return (true);
}
