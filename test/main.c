#include "libasm.h"

void		ft_main_strcmp(void)
{
    // Empty strings
    printf("-------------------ft_strcmp-------------------\n");
    printf("ft_strcmp: %d\n", ft_strcmp("", "Hello World!"));
    printf("strcmp: %d\n", strcmp("", "Hello World!"));
    printf("----------\n");

    printf("ft_strcmp: %d\n", ft_strcmp("Hello World!", ""));
    printf("strcmp: %d\n", strcmp("Hello World!", ""));
    printf("----------\n");

    // Identical strings
    printf("ft_strcmp: %d\n", ft_strcmp("Bonjour", "Bonjour"));
    printf("strcmp: %d\n", strcmp("Bonjour", "Bonjour"));
    printf("----------\n");

    // Different strings
    printf("ft_strcmp: %d\n", ft_strcmp("Bonjour", "Hello"));
    printf("strcmp: %d\n", strcmp("Bonjour", "Hello"));
    printf("----------\n");
}

int main() {
    printf("\033[0;34mSTRLEN TEST\033[0m\n");
    test_strlen();
    printf("\033[0;34mSTRCPY TEST\033[0m\n");
    test_strcpy();
    printf("\033[0;34mSTRCMP TEST\033[0m\n");
    ft_main_strcmp();
    return 0;
}