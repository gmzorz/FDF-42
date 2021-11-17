/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handler.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 15:50:14 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 16:04:26 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	mouse_handle(int32_t button, int32_t u, int32_t v, t_fdf *scene)
{
	(void)u;
	(void)v;
	if (button == 4)
		scale_up(scene);
	if (button == 5)
		scale_down(scene);
	flush_framebuffer(&scene->framebuffer);
	draw(scene);
	mlx_put_image_to_window(scene->buffer.mlx,
		scene->buffer.win,
		scene->buffer.image, 0, 0);
	return (1);
}
