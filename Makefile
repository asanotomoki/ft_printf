NAME	=	libftprintf.a
INCLUDE = ./include
LIBFT = ./libft
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I $(INCLUDE)
SRCS	=	ft_printf.c \
			ft_vprintf.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putptr.c \
			ft_printf_utils.c

OBJS	=	$(SRCS:.c=.o)
AR = ar
ARFLAFS = rcs
RM = rm -f
TARGET = ./include

all: $(NAME) 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(ARFLAFS) $(NAME) $(OBJS)

clean:
	make clean -C LIBFT
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C LIBFT
	$(RM) $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) main.c $(NAME)  -fsanitize=address -g
	./a.out
	rm a.out

.PHONY: all bonus fclean clean re test
