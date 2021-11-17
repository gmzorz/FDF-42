/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   framebuffer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/09 11:58:10 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/26 16:02:38 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>

void	flush_framebuffer(t_vec **framebuffer)
{
	uint32_t	idx;

	idx = 0;
	while (idx < RES_W * RES_H)
	{
		(*framebuffer)[idx] = (t_vec){0.0f, 0.0f, 0.0f, INFINITY};
		idx += 1;
	}
}

t_vec	*init_framebuffer(void)
{
	t_vec	*framebuffer;

	framebuffer = (t_vec *)ft_calloc(1, sizeof(t_vec) * RES_W * RES_H);
	if (framebuffer == NULL)
		return (NULL);
	flush_framebuffer(&framebuffer);
	return (framebuffer);
}
