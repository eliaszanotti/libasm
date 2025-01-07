NAME = libasm.a

NASM = nasm
NASM_FLAGS = -felf64
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/ft_strlen.s \
		# src/ft_strcpy.s \
		src/ft_strcmp.s \
		src/ft_write.s \
		src/ft_read.s \
		src/ft_strdup.s \

OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.s
	$(NASM) $(NASM_FLAGS) $< -o $@

# %.o: %.c
# $(CC) $(CFLAGS) -c $< -o $@

test: main.o $(NAME)
	$(CC) main.o -L. -lasm -o test_program -lc

clean:
	rm -f $(OBJS) main.o

fclean: clean
	rm -f $(NAME) test_program

re: fclean all