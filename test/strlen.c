#include "libasm.h"

static void _strlen_print_result(const char *str) {
    size_t ft_strlen_result = ft_strlen(str);
    size_t strlen_result = strlen(str);

    printf("--- %s ---\n", str);
    printf("ft_strlen : %zu\n", ft_strlen_result);
    printf("strlen    : %zu\n", strlen_result);
    if (ft_strlen_result == strlen_result) {
        printf("\033[0;32mOK\033[0m\n\n");
    } else {
        printf("\033[0;31mFAILED\033[0m\n\n");
    }
}

void test_strlen() {
    char *strs[] = {
        "Hello, world!",
        "",
        "A",
        "1234567890",
        "This is a longer string to test the length function.",
        "Special characters: !@#$%^&*()_+",
        "こんにちは",
        NULL
    };

    for (int i = 0; strs[i] != NULL; i++) {
        _strlen_print_result(strs[i]);
    }

    char long_str[1001];
    for (int i = 0; i < 1000; i++) {
        long_str[i] = 'A';
    }
    long_str[1000] = '\0';
    _strlen_print_result(long_str);
}