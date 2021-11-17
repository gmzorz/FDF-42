/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   construct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 12:29:03 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/25 16:02:54 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

/*
**	Construct faces (two triangles, six vertices) using already existing
**	vertices parsed in assign_line(). pointers, ofcourse!
**	The indexing of scene->faces[j].vertex may seem ordered the wrong way,
**	but it is correct in a culling sense.
*/

void	construct_triangles(t_fdf *scene)
{
	uint32_t	pos[2];
	uint32_t	i;
	uint32_t	j;

	ft_memset(pos, 0, sizeof(uint32_t) * 2);
	j = 0;
	while (pos[Y] < scene->height - 1)
	{
		while (pos[X] < scene->width - 1)
		{
			i = pos[Y] * scene->width + pos[X];
			scene->faces[j].vertex[2] = &scene->vertices[i];
			scene->faces[j].vertex[1] = &scene->vertices[i + 1];
			scene->faces[j].vertex[0] = &scene->vertices[i + 1 + scene->width];
			scene->faces[j + 1].vertex[0] = &scene->vertices[i];
			scene->faces[j + 1].vertex[1] = &scene->vertices[i + scene->width];
			scene->faces[j + 1].vertex[2] = \
				&scene->vertices[i + scene->width + 1];
			j += 2;
			pos[X] += 1;
		}
		pos[X] = 0;
		pos[Y] += 1;
	}
	set_scene_parameters(scene);
}
