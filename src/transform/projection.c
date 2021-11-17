/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   projection.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 10:39:59 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:41:16 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_projection(t_fdf *scene)
{
	scene->projection = !scene->projection;
	if (scene->projection == PROJECTION_PERSPECTIVE)
	{
		mlx_mouse_hide();
		mlx_mouse_move(scene->buffer.win, RES_W / 2, RES_H / 2);
	}
	else
		mlx_mouse_show();
}
