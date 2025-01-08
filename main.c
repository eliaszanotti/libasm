#include <stdio.h>
#include <errno.h>

extern size_t ft_strlen(const char *str);

void test_strlen() {
    const char *test_str = "Hello, world!";
    size_t length = ft_strlen(test_str);
    printf("Length of '%s' is %zu\n", test_str, length);
}

int main() {
	test_strlen();
    return 0;
}