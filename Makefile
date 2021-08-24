NAME	=	pipex

SRCS	=	./lib/ft_calloc.c\
			./lib/ft_exit_code.c\
			./lib/ft_memset.c\
			./lib/ft_newarray.c\
			./lib/ft_putchar_fd.c\
			./lib/ft_putstr_fd.c\
			./lib/ft_split.c\
			./lib/ft_strcat.c\
			./lib/ft_strdup.c\
			./lib/ft_strjoin.c\
			./lib/ft_strlcpy.c\
			./lib/ft_strlen.c\
			./lib/ft_strncmp.c\
			./lib/ft_strrchr.c\
			./srcs/path.c\
			./srcs/pipex.c\

CC		=	gcc

CFLAGS		=	-Werror -Wextra -Wall -fsanitize=address -g

DEL			=	rm -f

OBJ 		=	$(addsuffix .o, $(basename $(SRCS)))

%.o: %.c
				$(CC) -c -o $@ $< $(CFLAGS)

all:			$(NAME)

$(NAME):$(OBJ)
				${CC} ${CFLAGS} -o ${NAME} ${OBJ}

clean:
				${DEL} ${OBJ}

fclean:			clean
				${DEL} ${NAME}

re:				clean all

.PHONY: 		clean re fclean all