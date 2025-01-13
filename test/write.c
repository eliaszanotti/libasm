#include "libasm.h"

static void _write_print_result(int fd, const char *str, size_t len) {
    ssize_t ft_write_result;
    ssize_t write_result;

    errno = 0;
    ft_write_result = ft_write(fd, str, len);
    int ft_errno = errno;

    errno = 0;
    write_result = write(fd, str, len);
    int std_errno = errno;

    printf("--- %s ---\n", str);
    printf("ft_write : %zd (errno: %d)\n", ft_write_result, ft_errno);
    printf("write    : %zd (errno: %d)\n", write_result, std_errno);
    if (ft_write_result == write_result && ft_errno == std_errno) {
        printf("\033[0;32mOK\033[0m\n\n");
    } else {
        printf("\033[0;31mFAILED\033[0m\n\n");
    }
}

void test_write() {
    char *strs[] = {
        "Hello, world!\n",
        "",
        "A\n",
        "1234567890\n",
        "This is a longer string to test the write function.\n",
        "Special characters: !@#$%^&*()_+\n",
        "こんにちは\n",
        NULL
    };

    for (int i = 0; strs[i] != NULL; i++) {
        _write_print_result(1, strs[i], strlen(strs[i]));
    }

    _write_print_result(-1, "This should fail\n", 17);
    _write_print_result(9999, "This should also fail\n", 21);
    _write_print_result(1, "This should fail with negative length\n", (size_t)-1);

    int fd = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    close(fd);
    _write_print_result(fd, "This should fail because the file is closed\n", 45);
    _write_print_result(1, NULL, 0);
}