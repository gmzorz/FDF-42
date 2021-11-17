/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   invert.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 16:11:18 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 16:11:53 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	invert_colors(t_fdf *scene)
{
	scene->buffer.invert = !scene->buffer.invert;
}
