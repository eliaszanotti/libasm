#include "libasm.h"

static void _strdup_print_result(const char *src) {
    char *ft_strdup_result;
    char *strdup_result;

    printf("--- %s ---\n", src ? src : "NULL");
    
    ft_strdup_result = ft_strdup(src);
    strdup_result = strdup(src);

    printf("ft_strdup : %s\n", ft_strdup_result ? ft_strdup_result : "NULL");
    printf("strdup    : %s\n", strdup_result ? strdup_result : "NULL");
    
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
    _strdup_print_result("");
    _strdup_print_result("A");
    _strdup_print_result("Hello\nWorld");
    _strdup_print_result("Hello\tWorld");
    _strdup_print_result("Hello\0World");

    _strdup_print_result("élias");
    _strdup_print_result("Hello 世界");
    _strdup_print_result("Hello 🌍");

    char long_str[1000];
    for (int i = 0; i < 999; i++) {
        long_str[i] = 'A';
    }
    long_str[999] = '\0';
    _strdup_print_result(long_str);

    _strdup_print_result("\x01\x02\x03");
    _strdup_print_result("\x7F\x80\x81");
    _strdup_print_result("Hello\n\t\r\0World");
    _strdup_print_result("Hello 👨‍👩‍👧‍👦 World");
}