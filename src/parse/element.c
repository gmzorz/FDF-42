/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   element.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 14:19:24 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 13:15:02 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdbool.h>
#include <error.h>

static int32_t	verify_int(const char *line)
{
	int32_t	idx;
	bool	sign;

	idx = 0;
	sign = false;
	while (line[idx] != '\0')
	{
		if (line[idx] == '-' && idx == 0 && !sign)
			sign = true;
		else if (!ft_isdigit(line[idx]))
			return (idx);
		idx += 1;
	}
	return (idx);
}

static t_vec	parse_color(char **line)
{
	t_vec		outvec;
	uint32_t	token_idx;
	uint32_t	str_idx;

	*line += 1;
	*line += ((*line)[0] == '0' && ft_toupper((*line)[1]) == 'X') << 1;
	outvec = (t_vec){0.0, 0.0, 0.0, 0.0};
	if (ft_strspn(*line, HEX_TOKENS) == 6 || ft_strspn(*line, HEX_TOKENSL) == 6)
	{
		str_idx = 0;
		while (str_idx < 6)
		{
			token_idx = 0;
			while (ft_toupper((*line)[str_idx]) != HEX_TOKENS[token_idx])
				token_idx += 1;
			outvec[str_idx / 2] += (token_idx * (str_idx % 2 == 0) << 4);
			outvec[str_idx / 2] += (token_idx * (str_idx % 2 != 0));
			str_idx += 1;
		}
		*line += 6;
		*line += ft_strspn(*line, DELIM_SPACE);
		return (outvec / 255.0f);
	}
	return ((t_vec){0.0, 0.0, 0.0, -1.0f});
}

bool	parse_element(char **line, int32_t *in, t_vec *color)
{
	char		*number;
	int32_t		len;
	int32_t		idx;

	*line += ft_strspn(*line, DELIM_SPACE);
	len = verify_int(*line);
	if (len == 0)
		return (error_msg(ERR_PAR_INT));
	idx = 0;
	number = (char *)ft_calloc(1, len + 1);
	if (number == NULL)
		return (error_msg(ERR_ALLOC_INT));
	while (idx < len)
	{
		number[idx] = **line;
		*line += 1;
		idx += 1;
	}
	*color = (t_vec){1.0, 1.0, 1.0, 0.0};
	if (**line && **line == ',')
		*color = parse_color(line);
	if (!ft_atoi(number, in) || (*color)[3] == -1.0f)
		return (error_free(number, ERR_PAR_INT));
	free(number);
	return (true);
}
