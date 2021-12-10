SRCS		= server.c		\
			  client.c

OBJS		= ${SRCS:.c=.o}

NAME		= minitalk.a

CC			= gcc

CCFLAGS 	= -Wall -Werror -Wextra

INCLUDES	= -I./includes -I./libft

all:		${NAME}


${NAME}:	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp ./libft/libft.a $(NAME)
			ar -r $(NAME) $(OBJS)
			gcc -o minitalk $(CCFLAGS) $(NAME)
			ranlib $(NAME)

clean:	
					$(MAKE) clean -C ./libft
					rm -f ${OBJS}

fclean:		clean
					$(MAKE) fclean -C ./libft
					rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
