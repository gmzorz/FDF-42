/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 14:21:57 by goosterl      #+#    #+#                 */
/*   Updated: 2021/06/15 15:35:39 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <libft.h>

bool	error_msg(char *msg)
{
	ft_putstr_fd("[ERROR]: ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
	return (false);
}
