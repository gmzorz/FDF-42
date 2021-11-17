/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 14:49:55 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 16:09:59 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	write_color(t_mlx *buffer,
	const uint32_t u,
	const uint32_t v,
	t_vec color)
{
	char		*location;

	if (u >= RES_W || v >= RES_H)
		return ;
	location = buffer->address
		+ (v * buffer->size_line
			+ u * (buffer->bpp / 8));
	saturate(&color);
	if (buffer->invert)
		color = 1.f - color;
	color *= 255.0;
	*(uint32_t *)location = (
			(int)color[R] << 16
			| (int)color[G] << 8
			| (int)color[B]);
}
