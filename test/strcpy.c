#include "libasm.h"

static void _strcpy_print_result(const char *src) {
    char ft_strcpy_result[1000];
    char strcpy_result[1000];
    ft_strcpy(ft_strcpy_result, src);
    strcpy(strcpy_result, src);

    printf("--- %s ---\n", src);
    printf("ft_strcpy : %s\n", ft_strcpy_result);
    printf("strcpy    : %s\n", strcpy_result);
    if (strcmp(ft_strcpy_result, strcpy_result) == 0) {
        printf("\033[0;32mOK\033[0m\n\n");
    } else {
        printf("\033[0;31mFAILED\033[0m\n\n");
    }
}

void test_strcpy(void) {
    char *strs[] = {
        "Hello, world!",
        "",
        "A",
        "1234567890",
        "This is a longer string to test the copy function.",
        "Special characters: !@#$%^&*()_+",
        "こんにちは",
        NULL
    };

    for (int i = 0; strs[i] != NULL; i++) {
        _strcpy_print_result(strs[i]);
    }
}