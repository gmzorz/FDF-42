/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 12:14:50 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/18 15:08:00 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_vec	convert(const uint32_t color)
{
	return ((t_vec){
		((color >> 16) & 0xFF) / 255.0,
		((color >> 8) & 0xFF) / 255.0,
		((color) & 0xFF) / 255.0,
		0.0});
}

t_vec	get_color_at(const t_mlx *buf, const uint32_t idx)
{
	char	*location;

	location = buf->address + (idx * (buf->bpp / 8));
	if (location == NULL)
		return ((t_vec){0.0, 0.0, 0.0, -1.0});
	return (convert(*(uint32_t *)location));
}
