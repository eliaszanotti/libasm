NAME = libasm.a

NASM = nasm
NASM_FLAGS = -felf64
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -Iinc

BUILD_DIR = .obj

SRCS_ASM =	src/ft_strlen.s \
			src/ft_strcpy.s \
			# src/ft_strcmp.s \
			# src/ft_write.s \
			# src/ft_read.s \
			# src/ft_strdup.s \

SRCS_C = test/main.c

OBJS_ASM = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS_ASM:.s=.o)))
OBJS_C = main.o

all: $(NAME)

$(NAME): $(OBJS_ASM)
	ar rcs $@ $^

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: src/%.s | $(BUILD_DIR)
	$(NASM) $(NASM_FLAGS) $< -o $@

$(OBJS_C): $(SRCS_C)
	$(CC) $(CC_FLAGS) -c $< -o $@

test: $(NAME) $(OBJS_C)
	$(CC) $(OBJS_C) -L. -lasm -o test_program -lc -Wl,-z,noexecstack

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME) test_program

re: fclean all