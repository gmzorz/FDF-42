/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visibility.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/29 13:23:33 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:31 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

bool	vertex_is_visible(const t_vec raster_space)
{
	return (raster_space[X] > 0
		&& raster_space[X] < RES_W - 1
		&& raster_space[Y] > 0
		&& raster_space[Y] < RES_H - 1);
}

/*
**	frustum culling, whether the face is visible in defined raster space
*/
bool	face_is_visible(const t_face face, t_fragment *frag)
{
	ft_memset(frag, 0, sizeof(t_fragment));
	if (!vertex_is_visible(face.vertex[0]->raster)
		&& !vertex_is_visible(face.vertex[1]->raster)
		&& !vertex_is_visible(face.vertex[2]->raster))
		return (false);
	frag->min = vmin(face.vertex[0]->raster, face.vertex[1]->raster);
	frag->min = vmin(frag->min, face.vertex[2]->raster);
	frag->max = vmax(face.vertex[0]->raster, face.vertex[1]->raster);
	frag->max = vmax(frag->max, face.vertex[2]->raster);
	return (frag->min[X] < RES_W
		&& frag->max[X] > 0
		&& frag->min[Y] < RES_H
		&& frag->max[Y] > 0);
}
