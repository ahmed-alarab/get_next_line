NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c \
       get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

HEADER = get_next_line.h

RM = rm -f
AR = ar rcs

# Default rule
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compile .c to .o
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	$(RM) $(OBJS)

# Remove everything
fclean: clean
	$(RM) $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
