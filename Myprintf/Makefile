FLAGS = -c -Wall -Wextra -Werror
LIBFT = libft/libft.a

SOURCES = ft_printf.c \
			ft_parser.c \
			ft_parser2.c \
			ft_accurasy2.c \
			ft_mystrchr.c \
			ft_allnull.c \
			ft_processorforstr.c \
			ft_processorforchar.c \
			ft_processorforu.c \
			ft_processorforu2.c \
			ft_processorforu3.c \
			ft_countsymbols.c \
			ft_processorforthexx.c \
			ft_processorforp.c \
			ft_processorforp2.c \
			ft_processorfordi.c \
			ft_processorfordii.c \
			ft_processorfordi2.c \
			ft_processorfordi3.c \

OBJECTS = $(SOURCES:.c=.o)

NAME = libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(MAKE) -C libft
	cp $(LIBFT) ./$(NAME)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

.c.o:
	gcc $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS)
	$(MAKE) clean -C libft


fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C libft

re: fclean all