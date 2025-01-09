#include <stdio.h>
#include <errno.h>
#include <string.h>

extern size_t ft_strlen(const char *str);

void strlen_print_result(const char *str) {
    size_t ft_strlen_result = ft_strlen(str);
    size_t strlen_result = strlen(str);
    printf("\n--- %s ---\n", str);
    printf("ft_strlen : %zu\n", ft_strlen_result);
    printf("strlen    : %zu\n", strlen_result);
    if (ft_strlen_result == strlen_result) {
        printf("\033[0;32mOK\033[0m\n");
    } else {
        printf("\033[0;31mFAILED\033[0m\n");
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
        NULL
    };

    for (int i = 0; strs[i] != NULL; i++) {
        strlen_print_result(strs[i]);
    }

    char long_str[1001];
    for (int i = 0; i < 1000; i++) {
        long_str[i] = 'A';
    }
    long_str[1000] = '\0';
    strlen_print_result(long_str);

    char *unicode_str = "こんにちは";
    strlen_print_result(unicode_str);
}

int main() {
	test_strlen();
    return 0;
}