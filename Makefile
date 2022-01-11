SRCS_C		= client.c			\
			  
SRCS_S		= server.c			\

SRCS_BC		= client_bonus.c	\

SRCS_BS		= server_bonus.c	\

OBJS_C		= ${SRCS_C:.c=.o}

OBJS_S		= ${SRCS_S:.c=.o}

OBJS_BC		= ${SRCS_BC:.c=.o}

OBJS_BS		= ${SRCS_BS:.c=.o}

NAME_C		= client

NAME_S		= server

NAME_BC		= client_bonus

NAME_BS		= server_bonus

CC			= gcc

CCFLAGS 	= -Wall -Werror -Wextra

INCLUDES	= -I./includes -I./libft

all:		${NAME_C} ${NAME_S}

bonus:		${NAME_BC} ${NAME_BS}

${NAME_C}:	$(OBJS_C)
			$(MAKE) bonus -C ./libft
			gcc -L./libft/ $(CCFLAGS) $(OBJS_C) ./libft/libft.a -o $(NAME_C)

${NAME_S}:	$(OBJS_S)
			gcc -L./libft/ $(CCFLAGS) $(OBJS_S) ./libft/libft.a -o $(NAME_S)

${NAME_BC}:	$(OBJS_BC)
			$(MAKE) bonus -C ./libft
			gcc -L./libft/ $(CCFLAGS) $(OBJS_BC) ./libft/libft.a -o $(NAME_BC)

${NAME_BS}:	$(OBJS_BS)
			gcc -L./libft/ $(CCFLAGS) $(OBJS_BS) ./libft/libft.a -o $(NAME_BS)

clean:	
					$(MAKE) clean -C ./libft
					rm -f ${OBJS_C} ${OBJS_S} ${OBJS_BC} ${OBJS_BS}

fclean:		clean
					$(MAKE) fclean -C ./libft
					rm -f ${NAME_C} ${NAME_S} ${NAME_BC} ${NAME_BS}

re:			fclean all

.PHONY:		all clean fclean re
