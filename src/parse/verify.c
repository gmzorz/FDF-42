/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 15:13:55 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 11:36:13 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gnl.h>
#include <fdf.h>
#include <fcntl.h>
#include <error.h>
#include <libft.h>

/*
**	Word count
*/
static size_t	line_width(char **line)
{
	size_t	width;

	width = 0;
	*line += ft_strspn(*line, DELIM_SPACE);
	while (ft_strcspn(*line, DELIM_SPACE))
	{
		*line += ft_strcspn(*line, DELIM_SPACE);
		if (ft_strspn(*line, DELIM_SPACE))
			*line += ft_strspn(*line, DELIM_SPACE);
		width += 1;
	}
	return (width);
}

static bool	init_filedata(t_fileinf *fdata, const char *file)
{
	fdata->line_width = 0;
	fdata->success = true;
	fdata->fd = open(file, O_RDONLY);
	if (fdata->fd < 3)
		return (error_msg(ERR_FDF_FD));
	if (!ft_matchend(file, ".fdf"))
		return (error_msg(ERR_FDF_EXT));
	return (true);
}

bool	verify_map(t_fdf *scene, const char *file)
{
	t_fileinf	fdata;
	static bool	empty_ln = false;

	if (!init_filedata(&fdata, file))
		return (false);
	while (get_next_line(fdata.fd, &fdata.line) > 0)
	{
		fdata.line_cpy = fdata.line;
		fdata.line_width = line_width(&fdata.line);
		scene->width += (!scene->width) * fdata.line_width;
		scene->height += (fdata.line_width > 0);
		fdata.success *= !(scene->width && fdata.line_width
				&& scene->width != fdata.line_width);
		fdata.success *= !(empty_ln && fdata.line_width);
		empty_ln = (scene->height && !empty_ln && !fdata.line_width);
		free(fdata.line_cpy);
	}
	free(fdata.line);
	close(fdata.fd);
	return (errorlvl_msg(fdata.success, ERR_MAP_SIZE));
}
