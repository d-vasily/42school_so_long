SRCS			= main_bonus.c utils_bonus.c create_map_bonus.c\
				init_and_check_map_bonus.c init_stuff_bonus.c\
				render_bonus.c move_handle_bonus.c

OBJ_DIR			= obj/

OBJS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

DEPS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

NAME			= so_long

LIBFT			= ../libft/libft.a

HEADERS			= so_long_bonus.h

CC				= gcc

FLAGS			= -Wall -Werror -Wextra -O3 -MMD

${OBJ_DIR}%.o: 	%.c
				${CC} ${FLAGS} -Imlx -c $< -o $@

all:			${OBJ_DIR} ${NAME}

${LIBFT}:		FORCE
				@${MAKE} -C ../libft all

${OBJ_DIR}:
				@mkdir -p ${OBJ_DIR}

${NAME}:		${OBJS} ${LIBFT} ${HEADERS}
				${CC} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${NAME} -L../libft -lft
				cp ${NAME} ../

FORCE:			;

clean:
				@${MAKE} -C ../libft clean
				@rm -rf ${OBJ_DIR}
				@echo "Clean: Done."

fclean:			clean
				@${MAKE} -C ../libft fclean
				@rm -f ../${NAME}
				@rm -f ${NAME}
				@echo "Fclean: Done."

re:				fclean all

.PHONY:			all FORCE clean fclean re

-include 		${DEPS}
