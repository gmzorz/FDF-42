/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: goosterl <goosterl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 14:06:11 by goosterl      #+#    #+#                 */
/*   Updated: 2021/10/27 12:55:01 by goosterl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdint.h>
# include <stdbool.h>
# include <geometry.h>
# include <buffer.h>
# include <math.h>
# include <stdlib.h>

# define DELIM_SPACE	" \t\n\v\f\r"
# define EPSILON 		1e-8
# define PI_DELTA		0.00174532925
# define MOVE_SPEED		200.f
# define MAX_MOUSE_MOVE	1.0f
# define HEX_TOKENS		"0123456789ABCDEF"
# define HEX_TOKENSL	"0123456789abcdef"

# define PROJECTION				unsigned int
# define PROJECTION_ISOMETRIC	0
# define PROJECTION_PERSPECTIVE	1

# define COLORVISUAL			unsigned int
# define COLOR_WHITE			0
# define COLOR_HEIGHT_GREYSCALE	1
# define COLOR_HEIGHT_HSV		2

# define DISPLAYMODE			unsigned int
# define DISPLAY_SQUARES		0
# define DISPLAY_TRIANGLES		1
# define DISPLAY_HORIZONTALS	2
# define DISPLAY_VERTICALS		3

# define EXIT_WINDOW	17
# define MASK_BUTTON	0L
# define KEY_DOWN		2
# define KEY_UP			3
# define MOUSE_DOWN		4
# define MOUSE_UP		5
# define MOTION			6
# define NUM_EVENTS		13

typedef struct s_fragment
{
	t_vec		min;
	t_vec		max;
	float		area;
}	t_fragment;

typedef struct s_face
{
	t_vertex	*vertex[3];	
	t_vec		edges[3];
	t_vec		normal;
	t_vec		normal_rgb;
	t_vec		world_normal;
	t_vec		origin;
}	t_face;

typedef struct s_fdf
{
	t_mlx			buffer;
	bool			height_from_image;
	PROJECTION		projection;
	COLORVISUAL		wire_color;
	DISPLAYMODE		wire_display;
	t_vertex		*vertices;
	t_face			*faces;
	t_mat			transform;
	t_mat			isometric;
	t_mat			rotation;
	size_t			num_vertices;
	size_t			num_faces;
	uint32_t		width;
	uint32_t		height;
	t_vec			min_bounds;
	t_vec			max_bounds;
	float			geo_size;
	t_vec			*framebuffer;
	t_vec			camera_speedscale;
}	t_fdf;

typedef struct s_key_lut
{
	int32_t		button;
	void		(*press)(t_fdf *scene);
}	t_key_lut;

t_fdf	*scene_alloc(void);
bool	scene_init(t_fdf *scene, const char *file);
void	setup_mlx(t_mlx *buffer);
void	setup_hook(t_fdf *scene);
t_vec	*init_framebuffer(void);
void	flush_framebuffer(t_vec **framebuffer);

bool	parse_map(t_fdf *scene, const char *file);
bool	parse_image(t_fdf *scene, const char *file);
bool	verify_map(t_fdf *scene, const char *file);
bool	parse_element(char **line, int32_t *in, t_vec *color);
bool	parse_skip(char **line, const char *delim, int skip_count);

/*
**	events
*/

int		mouse_handle(int32_t button, int32_t u, int32_t v, t_fdf *scene);
void	set_projection(t_fdf *scene);
void	scale_up(t_fdf *scene);
void	scale_down(t_fdf *scene);
void	move_right(t_fdf *scene);
void	move_left(t_fdf *scene);
void	move_up(t_fdf *scene);
void	move_down(t_fdf *scene);
void	move_forward(t_fdf *scene);
void	move_back(t_fdf *scene);
void	world_to_camera(
			t_vertex *vertices,
			const size_t num_vertices,
			t_fdf *scene);
void	camera_to_raster(
			t_vertex *vertices,
			const size_t num_vertices,
			const PROJECTION projection);
void	pan_camera(const int32_t delta_x, const int32_t delta_y, t_fdf *scene);
void	axis_pan(t_mat matrix, const float angle, const t_vec axis);
void	axis_pan_about_y(t_mat matrix, const float angle);
void	axis_pan_about_x(t_mat matrix, const float angle);
void	zoom_in(t_fdf *scene);
void	zoom_out(t_fdf *scene);
void	free_cam(t_fdf *scene);
void	set_height_color(t_fdf *scene);
void	set_wireframe_display(t_fdf *scene);
void	invert_colors(t_fdf *scene);
int		exit_prog(void *catch);
void	exit_prog_hook(t_fdf *scene);

/*
**	 scene utils
*/

void	construct_triangles(t_fdf *scene);
void	draw(t_fdf *scene);
void	draw_line(
			t_vec *framebuffer,
			const t_vec coords[2],
			const t_vec color[2],
			const PROJECTION projection);
void	present(t_fdf *scene);
bool	face_is_visible(const t_face face, t_fragment *frag);
void	set_scene_parameters(t_fdf *scene);

#endif
