# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: goosterl <goosterl@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 11:31:13 by goosterl      #+#    #+#                  #
#    Updated: 2021/10/27 14:20:53 by goosterl      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
CC			=	gcc
CCFLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address
FRAMEW		=	-framework AppKit -framework OpenGl
MLX_PATH	=	./minilibx_opengl/
MLX_LIB		=	libmlx.a
LIBINC		=	./libft/libft.a					\
				$(MLX_LIB)		
SRC			=	./src/fdf.c							\
				\
				./src/vec/length.c					\
				./src/vec/normalize.c				\
				./src/vec/saturate.c				\
				./src/vec/clamp.c					\
				./src/vec/dot.c						\
				./src/vec/minmax.c					\
				\
				./src/mat/mat.c						\
				./src/mat/mul.c						\
				./src/mat/transpose.c				\
				\
				./src/gnl/gnl.c						\
				./src/gnl/gnl_utils.c				\
				\
				./src/parse/map.c					\
				./src/parse/verify.c				\
				./src/parse/element.c				\
				./src/parse/image.c					\
				\
				./src/error/message.c				\
				./src/error/message_lvl.c			\
				./src/error/free_msg.c				\
				\
				./src/init/scene.c					\
				./src/init/mlx.c					\
				./src/init/hook.c					\
				./src/init/framebuffer.c			\
				\
				./src/buffer/write_color.c			\
				./src/buffer/get_color.c			\
				\
				./src/transform/height.c			\
				./src/transform/handler.c			\
				./src/transform/move_x.c			\
				./src/transform/move_y.c			\
				./src/transform/move_z.c			\
				./src/transform/world_to_camera.c	\
				./src/transform/camera_to_raster.c	\
				./src/transform/camera.c			\
				./src/transform/zoom.c				\
				./src/transform/axis_pan.c			\
				./src/transform/projection.c		\
				./src/transform/color.c				\
				./src/transform/wireframe_display.c	\
				./src/transform/invert.c			\
				\
				./src/scene/draw.c					\
				./src/scene/draw_line.c				\
				./src/scene/present.c				\
				./src/scene/visibility.c			\
				./src/scene/construct.c				\
				./src/scene/set_params.c			\
				./src/scene/exit.c

OBJ			=	$(SRC:.c=.o)
INC			=	./includes/

$(NAME):		$(OBJ)
				make -C ./libft/
				make -C $(MLX_PATH)
				cp $(MLX_PATH)$(MLX_LIB) $(MLX_LIB)
				$(CC) $(CCFLAGS) $(FRAMEW) $(LIBINC) $(OBJ) -o $(NAME)

all:			$(NAME)

%.o:			%.c
				$(CC) -I $(INC) $(CCFLAGS) -c -o $@ $<

clean:
				rm -rf $(OBJ)

fclean:			clean
				rm -rf $(LIBINC)
				rm -rf $(NAME)
				make fclean -C ./libft
				make clean -C $(MLX_PATH)

re:				fclean all

archapple:
				exec arch -arm64e zsh

archintel:
				exec arch -x86_64 zsh

.PHONY:			all clean fclean re
