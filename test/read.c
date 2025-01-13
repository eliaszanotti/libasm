#include "libasm.h"

static void _read_print_result(int fd, char *buffer, size_t len) {
    ssize_t ft_read_result;
    ssize_t read_result;

    errno = 0;
    ft_read_result = ft_read(fd, buffer, len);
    int ft_errno = errno;

    errno = 0;
    read_result = read(fd, buffer, len);
    int std_errno = errno;

    printf("--- Buffer: \"%.*s\" ---\n", (int)len, buffer);
    printf("ft_read  : %zd (errno: %d)\n", ft_read_result, ft_errno);
    printf("read     : %zd (errno: %d)\n", read_result, std_errno);
    if (ft_read_result == read_result && ft_errno == std_errno) {
        printf("\033[0;32mOK\033[0m\n\n");
    } else {
        printf("\033[0;31mFAILED\033[0m\n\n");
    }
}

void test_read() {
    char buffer[100];
    int fd = open("test_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "Hello, world!\nThis is a test file.\n", 36);
    close(fd);

    fd = open("test_file", O_RDONLY);
    if (fd < 0) {
        perror("Failed to open test_file");
        return;
    }

    _read_print_result(fd, buffer, 20);
    _read_print_result(fd, buffer, 50);
    close(fd);
    _read_print_result(fd, buffer, 20);
    _read_print_result(-1, buffer, 20);
    _read_print_result(9999, buffer, 20);
    remove("test_file");
}