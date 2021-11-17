/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 15:25:51 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 12:30:28 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdint.h>
#include <math.h>
#include <vec.h>
#include <buffer.h>

static int	key_exit_handle(int key, void *catch)
{
	const t_vec	cam_speed = {1.0f, 1.0f, 1.0f, 0.0f};
	t_fdf		*scene;

	scene = (t_fdf *)catch;
	(void)key;
	scene->camera_speedscale = cam_speed;
	return (1);
}

static int	key_handle(int key, void *catch)
{
	const t_vec		cam_speed = {2.5f, 2.5f, 2.5f, 0.0f};
	const t_key_lut	look_up[NUM_EVENTS] = {
		{13, move_forward}, {1, move_back}, {0, move_right}, {2, move_left},
		{12, move_up}, {14, move_down}, {24, zoom_in}, {27, zoom_out},
		{3, set_projection}, {8, set_height_color}, {9, set_wireframe_display},
		{34, invert_colors}, {53, exit_prog_hook}
	};
	t_fdf			*scene;
	int32_t			idx;

	idx = 0;
	scene = (t_fdf *)catch;
	if (key == 257)
		scene->camera_speedscale = cam_speed;
	while (idx < NUM_EVENTS)
	{
		if (key == look_up[idx].button)
			look_up[idx].press(scene);
		idx += 1;
	}
	flush_framebuffer(&scene->framebuffer);
	draw(scene);
	mlx_put_image_to_window(scene->buffer.mlx,
		scene->buffer.win, scene->buffer.image, 0, 0);
	return (1);
}

static int	look_handle(int32_t x, int32_t y, t_fdf *scene)
{
	const int32_t	center[2] = {RES_W / 2, RES_H / 2};

	if (y < 0)
		return (0);
	if (scene->projection == PROJECTION_PERSPECTIVE)
	{
		mlx_mouse_hide();
		pan_camera(x - center[X], y - center[Y], scene);
		mlx_mouse_move(scene->buffer.win, center[X], center[Y]);
	}
	else
	{
		mlx_mouse_show();
		return (0);
	}
	flush_framebuffer(&scene->framebuffer);
	draw(scene);
	mlx_put_image_to_window(scene->buffer.mlx,
		scene->buffer.win,
		scene->buffer.image, 0, 0);
	return (0);
}

void	setup_hook(t_fdf *scene)
{
	mlx_mouse_hook(scene->buffer.win, mouse_handle, scene);
	mlx_hook(scene->buffer.win, EXIT_WINDOW, MASK_BUTTON, exit_prog, scene);
	mlx_hook(scene->buffer.win, KEY_DOWN, MASK_BUTTON, key_handle, scene);
	mlx_hook(scene->buffer.win, KEY_UP, MASK_BUTTON, key_exit_handle, scene);
	mlx_hook(scene->buffer.win, MOTION, MASK_BUTTON, look_handle, scene);
}
