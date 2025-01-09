#include "libasm.h"

void _strcmp_print_result(const char *s1, const char *s2) {
    int ft_strcmp_result = ft_strcmp(s1, s2);
    int strcmp_result = strcmp(s1, s2);

    printf("--- %s | %s ---\n", s1, s2);
    printf("ft_strcmp : %d\n", ft_strcmp_result);
    printf("strcmp    : %d\n", strcmp_result);
    if (ft_strcmp_result == strcmp_result) {
        printf("\033[0;32mOK\033[0m\n\n");
    } else {
        printf("\033[0;31mFAILED\033[0m\n\n");
    }
}

void test_strcmp() {
    _strcmp_print_result("elias", "elias");
    _strcmp_print_result("", "Hello World!");
    _strcmp_print_result("Hello World!", "");
    _strcmp_print_result("Bonjour", "Bonjour");
    _strcmp_print_result("Bonjour", "Hello");
    _strcmp_print_result("abc", "abc");
    _strcmp_print_result("abc", "abcd");
    _strcmp_print_result("abcd", "abc");
    _strcmp_print_result("Hello", "hello");
    _strcmp_print_result("123", "123");
    _strcmp_print_result("123", "456");
}