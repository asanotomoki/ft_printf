NAME	=	libftprintf.a
INCLUDE = include
LIBFT = ./libft
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I $(INCLUDE)
SRCS	=	ft_printf.c ft_get_size.c ft_vprintf.c 
OBJS	=	$(SRCS:.c=.o)
AR = ar
ARFLAFS = rcs
RM = rm -f

all: $(NAME) 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C LIBFT
	$(AR) $(ARFLAFS) $(NAME) $(OBJS) $(LIBFT)/*.o $^

clean:
	make clean -C LIBFT
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C LIBFT
	$(RM) $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) main.c $(NAME)
	./a.out

.PHONY: all bonus fclean clean re test
