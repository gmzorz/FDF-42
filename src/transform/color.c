/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 13:02:07 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 13:06:07 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_height_color(t_fdf *scene)
{
	scene->wire_color = (scene->wire_color + 1) % 3;
}
