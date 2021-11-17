/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 13:27:53 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 13:27:03 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <vec.h>
#include <error.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_fdf	*scene;

	scene = scene_alloc();
	if (!scene)
		return (error_msg(ERR_ALLOC_SCENE));
	if (argc != 2)
		return (error_free(scene, ERR_BAD_INPUT));
	if (!scene_init(scene, argv[1]))
		return (error_free(scene, ERR_ALLOC_SCENE));
	mlx_clear_window(scene->buffer.mlx, scene->buffer.win);
	draw(scene);
	mlx_put_image_to_window(scene->buffer.mlx,
		scene->buffer.win,
		scene->buffer.image, 0, 0);
	mlx_loop(scene->buffer.mlx);
	return (1);
}
