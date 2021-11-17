/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 12:28:16 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 12:30:40 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	exit_prog(void *catch)
{
	t_fdf	*scene;

	scene = (t_fdf *)catch;
	free(scene->vertices);
	free(scene->faces);
	free(scene->framebuffer);
	free(scene);
	exit(1);
	return (1);
}

void	exit_prog_hook(t_fdf *scene)
{
	free(scene->vertices);
	free(scene->faces);
	free(scene->framebuffer);
	free(scene);
	exit(1);
}
