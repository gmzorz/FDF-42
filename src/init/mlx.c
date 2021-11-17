/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 12:40:30 by goosterl      #+#    #+#                 */
/*   Updated: 2021/09/27 12:23:10 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	setup_mlx(t_mlx *buffer)
{
	buffer->mlx = mlx_init();
	buffer->win = mlx_new_window(buffer->mlx, RES_W, RES_H, TITLE);
	buffer->image = mlx_new_image(buffer->mlx, RES_W, RES_H);
	buffer->address = mlx_get_data_addr(buffer->image,
			&buffer->bpp, &buffer->size_line, &buffer->endian);
	buffer->width = RES_W;
	buffer->height = RES_H;
}
