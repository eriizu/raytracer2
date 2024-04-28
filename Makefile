##
## Makefile for misc in /home/elise/delivery/.misc
##
## Made by Élise Philippe
## Login   <elise@epitech.net>
##
## Started on  Mon Nov  7 11:39:45 2016 Élise Philippe
## Last update Sun May 28 22:57:43 2017 Élise Philippe
##

CC	=	gcc

RM	=	rm -fv

NAME	=	raytracer2

LIBACP	=	lib/acp/libacp.a

SRCS	=	src/main.c				\
		src/launchers/bootstrap_import.c	\
		src/launchers/bootstrap_engine.c	\
		src/launchers/bootstrap_threads.c	\
		src/launchers/maintain_engine.c		\
		src/str.c				\
		src/helper.c				\
		src/launchers/open_window.c		\
		src/data_gathering/data_nuke.c		\
		src/data_gathering/get_opt.c		\
		src/data_gathering/fd_errors.c		\
		src/data_gathering/list.c		\
		src/data_gathering/load_data.c		\
		src/data_gathering/match.c		\
		src/data_gathering/objects_creation.c	\
		src/data_gathering/objects_pr_texture.c	\
		src/data_gathering/objects_limit.c	\
		src/data_gathering/objects_brightness.c	\
		src/vectors/rotate.c			\
		src/vectors/translate.c			\
		src/vectors/normalize.c			\
		src/vectors/dot_product.c		\
		src/objects/cone.c			\
		src/objects/cylinder.c			\
		src/objects/limited.c			\
		src/objects/plane.c			\
		src/objects/sphere.c			\
		src/objects/utils.c			\
		src/objects/default_colors.c		\
		src/data_gathering/objs_types.c		\
		src/render/render_export.c		\
		src/render/light.c			\
		src/render/calc_dir_vector.c		\
		src/render/get_intersection.c		\
		src/render/my_put_pixel.c		\
		src/render/colored_light_effect.c	\
		src/render/obj_fctn_shunter.c		\
		src/render/raytrace.c			\
		src/render/progress.c			\
		src/render/set_color.c			\
		src/render/std_effects.c		\
		src/render/set_brightness.c		\
		src/render/reflect.c			\
		src/render/refract.c			\
		src/procedural_texturing/chess_board.c	\
		src/procedural_texturing/perlin_val.c	\
		src/procedural_texturing/perlin_col.c	\
		src/procedural_texturing/perlin_tab.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wextra -Wall

##CFLAGS	+=	-Werror

CFLAGS	+=	-I include/

LDFLAGS	=	-L./lib/acp -lacp -lcsfml-graphics -lcsfml-window -lcsfml-system -lm -lpthread

ifndef VERBOSE
 MAKEFLAGS	+=	--no-print-directory
endif

GREEN	=	\033[0;32m

RESET	=	\033[0m

all: $(NAME)

$(LIBACP):
	@$(MAKE) -C lib/acp/

$(NAME): $(LIBACP) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo -e "\n$(GREEN)$(NAME) built$(RESET)\n--------------------"

clean:
	@$(MAKE) fclean -C lib/acp
	@echo -en "cleaned " ; $(RM) $(OBJS) | wc -l | tr -d '\n'
	@echo -e " of $(NAME)'s object files"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
