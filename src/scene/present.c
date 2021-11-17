/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   present.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/27 11:23:57 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:27 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
#include <fdf.h>

void	present(t_fdf *scene)
{
	uint32_t	screen[2];
	uint32_t	pixel_idx;
	t_vec		pixel;

	screen[X] = 0;
	screen[Y] = 0;
	while (screen[Y] < RES_H)
	{
		while (screen[X] < RES_W)
		{
			pixel_idx = screen[Y] * RES_H + screen[X];
			pixel = scene->framebuffer[pixel_idx];
			write_color(&scene->buffer, screen[X], screen[Y], pixel);
			screen[X] += 1;
		}
		screen[X] = 0;
		screen[Y] += 1;
	}
}
