NAME = libasm.a

NASM = nasm
NASM_FLAGS = -f elf6
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/ft_strlen.s \
		src/ft_strcpy.s \
		src/ft_strcmp.s \
		src/ft_write.s \
		src/ft_read.s \
		src/ft_strdup.s \
		