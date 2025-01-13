#include "libasm.h"

static void _strdup_print_result(const char *src) {
    char *ft_strdup_result;
    char *strdup_result;

    ft_strdup_result = ft_strdup(src);
    strdup_result = strdup(src);

    printf("--- %s ---\n", src);
    printf("ft_strdup : %s\n", ft_strdup_result);
    printf("strdup    : %s\n", strdup_result);
    if ((ft_strdup_result == NULL && strdup_result == NULL) || 
        (ft_strdup_result != NULL && strdup_result != NULL && strcmp(ft_strdup_result, strdup_result) == 0)) {
        printf("\033[0;32mOK\033[0m\n\n");
    } else {
        printf("\033[0;31mFAILED\033[0m\n\n");
    }

    free(ft_strdup_result);
    free(strdup_result);
}

void test_strdup(void) {
    char *strs[] = {
        "Hello, world!",
        "",
        "A",
        "1234567890",
        "This is a longer string to test the duplication function.",
        "Special characters: !@#$%^&*()_+",
        "こんにちは",
        NULL
    };

    for (int i = 0; strs[i] != NULL; i++) {
        _strdup_print_result(strs[i]);
    }
}