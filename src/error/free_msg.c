/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_msg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 15:33:47 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 13:25:25 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <libft.h>
#include <stdlib.h>

bool	error_free(void *chunk, char *msg)
{
	free(chunk);
	ft_putstr_fd("[ERROR]: ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	return (false);
}
