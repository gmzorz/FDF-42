/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wireframe_display.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 13:19:00 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 16:29:12 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_wireframe_display(t_fdf *scene)
{
	scene->wire_display = (scene->wire_display + 1) % 4;
}
