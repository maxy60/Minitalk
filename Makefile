SRCS_C		= server.c		\
			  
SRCS_S		= client.c		\

OBJS_C		= ${SRCS_C:.c=.o}

OBJS_S		= ${SRCS_S:.c=.o}

NAME_C		= client

NAME_S		= server

CC			= gcc

CCFLAGS 	= -Wall -Werror -Wextra

INCLUDES	= -I./includes -I./libft

all:		${NAME_C} ${NAME_S}


${NAME_C}:	$(OBJS_C)
			$(MAKE) bonus -C ./libft
			gcc -L./libft $(CCFLAGS) $(OBJS_C) -o $(NAME_C)

${NAME_S}:	$(OBJS_S)
			gcc $(CCFLAGS) $(OBJS_S) -o $(NAME_S)

clean:	
					$(MAKE) clean -C ./libft
					rm -f ${OBJS_C} ${OBJS_S}

fclean:		clean
					$(MAKE) fclean -C ./libft
					rm -f ${NAME_C} ${NAME_S}

re:			fclean all

.PHONY:		all clean fclean re
