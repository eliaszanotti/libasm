#include "libasm.h"

static void _strcmp_print_result(const char *s1, const char *s2) {
    int ft_strcmp_result = ft_strcmp(s1, s2);
    int strcmp_result = strcmp(s1, s2);

    printf("--- %s | %s ---\n", s1 ? s1 : "NULL", s2 ? s2 : "NULL");
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
    
    _strcmp_print_result("Hello\nWorld", "Hello\nWorld");
    _strcmp_print_result("Hello\tWorld", "Hello\tWorld");
    _strcmp_print_result("Hello\0World", "Hello\0World");
    
    _strcmp_print_result("élias", "elias");
    _strcmp_print_result("Hello 世界", "Hello World");
    _strcmp_print_result("Hello 🌍", "Hello World");
    
    char long_str1[1000] = "A";
    char long_str2[1000] = "A";
    for (int i = 1; i < 999; i++) {
        long_str1[i] = 'A';
        long_str2[i] = 'A';
    }
    long_str1[999] = '\0';
    long_str2[999] = '\0';
    _strcmp_print_result(long_str1, long_str2);
    
    long_str2[998] = 'B';
    _strcmp_print_result(long_str1, long_str2);

    _strcmp_print_result("\x01\x02\x03", "\x01\x02\x03");
    _strcmp_print_result("\x01\x02\x03", "\x01\x02\x04");
    
    _strcmp_print_result("\x7F\x80\x81", "\x7F\x80\x81");
    _strcmp_print_result("\x7F\x80\x81", "\x7F\x80\x82");
}