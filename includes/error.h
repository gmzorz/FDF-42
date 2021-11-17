/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 14:24:43 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 13:15:18 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <stdbool.h>

# define ERR_PAR_INT			"Failed to parse integer"
# define ERR_FDF_EXT			"Bad file extension"
# define ERR_FDF_FD				"Bad file descriptor"
# define ERR_NO_FILE_CONTENTS	"File is empty"
# define ERR_VERIFY				"Failed to verify map validity (BAD MAP)"
# define ERR_PARSE				"Failed to parse map"
# define ERR_ALLOC_SCENE		"Failed to allocate for scene"
# define ERR_ALLOC_MAP			"Failed to allocate for map"
# define ERR_ALLOC_VERT			"Failed to allocate for map vertices"
# define ERR_MAP_SIZE			"Map size is not rectangular"
# define ERR_EMP_LN				"Empty line in file"
# define ERR_PAR_DELIM			"Failed to parse delimiter"
# define ERR_INIT_MLX			"Could not set up MinilibX"
# define ERR_PAR_IMAGE			"Image not found"
# define ERR_BAD_INPUT			"Bad arguments"
# define ERR_ALLOC_INT			"Int alloc failed"

bool	error_msg(char *msg);
bool	errorlvl_msg(bool status, char *msg);
bool	error_free(void *chunk, char *msg);

#endif
