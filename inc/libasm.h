#ifndef _LIBASM_H
#define _LIBASM_H

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);

void test_strlen(void);
void test_strcpy(void);
void test_strcmp(void);
void test_write(void);

#endif