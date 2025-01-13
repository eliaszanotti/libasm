#include "libasm.h"

static void _read_print_result(int fd, char *buffer, size_t len) {
    ssize_t ft_read_result;
    ssize_t read_result;

    lseek(fd, 0, SEEK_SET);
    errno = 0;
    ft_read_result = ft_read(fd, buffer, len);
    int ft_errno = errno;

    lseek(fd, 0, SEEK_SET);
    errno = 0;
    read_result = read(fd, buffer, len);
    int std_errno = errno;

    printf("--- test_file ---\n");
    printf("ft_read  : buffer = %s | %zd (errno: %d)\n", buffer, ft_read_result, ft_errno);
    printf("read     : buffer = %s | %zd (errno: %d)\n", buffer, read_result, std_errno);
    if (ft_read_result == read_result && ft_errno == std_errno) {
        printf("\033[0;32mOK\033[0m\n\n");
    } else {
        printf("\033[0;31mFAILED\033[0m\n\n");
    }
}

void test_read() {
    char buffer[100];
    int fd = open("test_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "Hello, world! This is a test file.", 35);
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