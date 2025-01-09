#ifndef _LIBASM_H
#define _LIBASM_H

#include <errno.h>
#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);

void test_strlen(void);
void test_strcpy(void);

#endif