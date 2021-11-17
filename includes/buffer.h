/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/18 11:55:26 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 16:12:39 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H
# include "../minilibx_opengl/mlx.h"
# include <stdint.h>
# include <vec.h>
# include <stdbool.h>
# ifndef RES_W
#  define RES_W		1024
# endif
# ifndef RES_H
#  define RES_H		1024
# endif
# define TITLE		"FdF"

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*image;
	void		*address;
	int			size_line;
	int			bpp;
	int			endian;
	uint32_t	width;
	uint32_t	height;
	bool		invert;
}	t_mlx;

void	write_color(t_mlx *buffer,
			const uint32_t u,
			const uint32_t v,
			t_vec color);

t_vec	get_color_at(const t_mlx *buf,
			const uint32_t idx);

#endif
