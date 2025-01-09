#include "libasm.h"

int main() {
    printf("\033[0;34mSTRLEN TEST\033[0m\n");
    test_strlen();
    printf("\033[0;34mSTRCPY TEST\033[0m\n");
    test_strcpy();
    printf("\033[0;34mSTRCMP TEST\033[0m\n");
    test_strcmp();
    return 0;
}