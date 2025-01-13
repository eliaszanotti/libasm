#include "libasm.h"

void		ft_tmp_main_write(void)
{
	printf("-------------------ft_write-------------------\n");
 	printf("ft_write : \n");
	printf("\nreturn = %ld\n", ft_write(0, "coucou", 6));
 	printf("write : \n");
	printf("\nreturn = %ld\n", write(0, "coucou", 6));
	printf("----------\n");
	printf("ft_write : \n");
	printf("\nreturn = %ld\n", ft_write(0, "test", 2));
 	printf("write : \n");
	printf("\nreturn = %ld\n", write(0, "test", 2));
	printf("----------\n");
	printf("ft_write : \n");
	printf("\nreturn = %ld\n", ft_write(0, "test", 1));
 	printf("write : \n");
	printf("\nreturn = %ld\n", write(0, "test", 1));
    printf("----------\n");
    const char *message = "Hello, world! Testing ft_write.\n";
    printf("Write in test_write.txt\n");
    FILE *file = fopen("./test/test_write.txt", "w");
    if (file) {
        int fd = fileno(file);
        ssize_t result = ft_write(fd, message, strlen(message));
        if (result < 0) {
            perror("ft_write");
        } else {
            printf("Successfully wrote %ld bytes to the file.\n", result);
        }
        fclose(file);
    } else {
        perror("fopen");
    }
}

int main() {
    printf("\033[0;34mSTRLEN TEST\033[0m\n");
    test_strlen();
    printf("\033[0;34mSTRCPY TEST\033[0m\n");
    test_strcpy();
    printf("\033[0;34mSTRCMP TEST\033[0m\n");
    test_strcmp();
    printf("\033[0;34mWRITE TEST\033[0m\n");
    test_write();
    printf("\033[0;34mREAD TEST\033[0m\n");
    test_read();
    return 0;
}