/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 13:40:09 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 14:05:59 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gnl.h>
#include <fdf.h>
#include <fcntl.h>
#include <error.h>
#include <libft.h>

/*
**	Assuming each block in the fdf pdf is unit length, the example image
**	clearly shows that a height of 10 would be equal to unit length (1.0)
**	therefore, we divide by 10.
**	Computing X/Y position based on index is pretty straightforward, however
**	because of the nature of the renderer i am swapping the Y and Z components.
**	(Z == DEPTH, not height)
*/

static bool	assign_line(char **line, t_fdf *scene)
{
	static size_t	y = 0;
	size_t			x;
	int				catch;
	float			half_size[2];
	uint32_t		loc;

	half_size[X] = (float)(scene->width - 1) / 2.f;
	half_size[Y] = (float)(scene->height - 1) / 2.f;
	x = 0;
	while (x < scene->width)
	{
		loc = y * scene->width + x;
		*line += ft_strspn(*line, DELIM_SPACE);
		if (!parse_element(line, &catch, &scene->vertices[loc].color))
			return (false);
		scene->vertices[loc].origin[X] = 100.f * ((float)x - half_size[X]);
		scene->vertices[loc].origin[Z] = 100.f * ((float)y - half_size[Y]);
		scene->vertices[loc].origin[Y] = 100.f * (float)catch;
		scene->vertices[loc].height = scene->vertices[loc].origin[Y];
		x += 1;
	}
	y += 1;
	return (true);
}

static bool	allocate_map(t_fdf *scene)
{
	scene->num_vertices = scene->width * scene->height;
	scene->num_faces = (scene->width - 1) * (scene->height - 1) * 2;
	scene->vertices = (t_vertex *)ft_calloc(1,
			sizeof(t_vertex) * scene->num_vertices);
	if (scene->vertices == NULL)
		return (error_msg(ERR_ALLOC_VERT));
	scene->faces = (t_face *)ft_calloc(1,
			sizeof(t_face) * scene->num_faces);
	if (scene->faces == NULL)
		return (error_msg(ERR_ALLOC_MAP));
	return (true);
}

bool	parse_map(t_fdf *scene, const char *file)
{
	t_fileinf	fdata;

	if (!allocate_map(scene))
		return (false);
	fdata.fd = open(file, O_RDONLY);
	if (fdata.fd < 3)
		return (error_msg(ERR_FDF_FD));
	while (get_next_line(fdata.fd, &fdata.line) > 0)
	{
		fdata.line_cpy = fdata.line;
		fdata.line += ft_strspn(fdata.line, DELIM_SPACE);
		if (fdata.line[0] != '\0')
			if (!assign_line(&fdata.line, scene))
				return (false);
		free(fdata.line_cpy);
	}
	free(fdata.line);
	close(fdata.fd);
	construct_triangles(scene);
	return (true);
}
