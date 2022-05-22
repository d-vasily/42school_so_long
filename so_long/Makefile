NAME		= mandatory

BONUS		= bonus

all:		${NAME}

${NAME}:	
			@rm -f bonus/so_long
			${MAKE} -C ./mandatory

${BONUS}:
			@rm -f mandatory/so_long
			${MAKE} -C bonus

clean:
			${MAKE} -C mandatory clean
			${MAKE} -C bonus clean

fclean:		clean
			${MAKE} -C mandatory fclean
			${MAKE} -C bonus fclean

re:			fclean all

.PHONY:		all clean fclean re ${NAME} ${BONUS}
