/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   geometry.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/08 13:18:13 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:31:40 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H
# include <col.h>
# include <stdbool.h>

typedef struct s_vertex
{
	t_vec		origin;
	float		height;
	t_vec		camera;
	t_vec		raster;
	t_vec		color;
	t_vec		basecolor;
}	t_vertex;

#endif
