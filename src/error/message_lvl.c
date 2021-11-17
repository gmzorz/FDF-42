/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message_lvl.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 10:11:07 by goosterl      #+#    #+#                 */
/*   Updated: 2021/06/16 10:14:23 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>
#include <libft.h>

bool	errorlvl_msg(bool status, char *msg)
{
	if (status == false)
	{
		ft_putstr_fd("[ERROR]: ", 1);
		ft_putstr_fd(msg, 1);
		ft_putstr_fd("\n", 1);
		return (false);
	}
	return (true);
}
