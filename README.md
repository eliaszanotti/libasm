# libasm

## Sommaire

- [Description](#description)
- [Compilation](#compilation)
- [Nettoyage](#nettoyage)
- [Utilisation dans un programme C](#utilisation-dans-un-programme-c)
- [Fonctions](#fonctions)
  - [1. ft_strlen](#1-ft_strlen)
  - [2. ft_strcpy](#2-ft_strcpy)
  - [3. ft_strcmp](#3-ft_strcmp)
  - [4. ft_write](#4-ft_write)
  - [5. ft_read](#5-ft_read)
  - [6. ft_strdup](#6-ft_strdup)

## Description

`libasm` est une bibliothèque en C qui implémente des fonctions de manipulation de chaînes de caractères et d'opérations d'entrée/sortie, similaires à celles de la bibliothèque standard. Cette bibliothèque est conçue pour aider à comprendre les concepts de bas niveau en C, notamment l'utilisation de l'assembleur pour implémenter des fonctions.

## Compilation

Pour compiler la bibliothèque, vous devez avoir `nasm` et `gcc` installés sur votre système. Suivez les étapes ci-dessous :

1. Clonez le dépôt ou téléchargez les fichiers sources.
2. Ouvrez un terminal et naviguez jusqu'au répertoire contenant les fichiers.
3. Exécutez la commande suivante pour compiler la bibliothèque :

```bash
make
```

Cela compilera la bibliothèque. Si vous souhaitez compiler les tests, utilisez :

```bash
make test
```

Ensuite, lancez le programme de test avec :

```bash
./test_program
```

## Nettoyage

Pour nettoyer les fichiers objets et l'archive statique, exécutez :

```bash
make clean
```

Pour supprimer tous les fichiers générés, y compris le programme de test, utilisez :

```bash
make fclean
```

Pour recompiler la bibliothèque et les tests, utilisez :

```bash
make re
```

## Utilisation dans un programme C

Incluez le fichier d'en-tête `libasm.h` dans vos fichiers C pour utiliser les fonctions de la bibliothèque :

```c
#include "libasm.h"
```

## Fonctions

### 1. `ft_strlen`

**Prototype :** `size_t ft_strlen(const char *str);`

**Man :** `man 3 strlen`

Cette fonction calcule la longueur d'une chaîne de caractères. Elle parcourt la chaîne jusqu'à rencontrer le caractère nul (`\0`) et retourne le nombre de caractères avant ce caractère.

### 2. `ft_strcpy`

**Prototype :** `char *ft_strcpy(char *dest, const char *src);`

**Man :** `man 3 strcpy`

Cette fonction copie la chaîne source (`src`) dans la chaîne de destination (`dest`). Elle retourne un pointeur vers la chaîne de destination. La fonction s'arrête lorsque le caractère nul est rencontré dans la chaîne source.

### 3. `ft_strcmp`

**Prototype :** `int ft_strcmp(const char *s1, const char *s2);`

**Man :** `man 3 strcmp`

Cette fonction compare deux chaînes de caractères. Elle retourne un entier inférieur, égal ou supérieur à zéro, selon que la première chaîne est respectivement inférieure, égale ou supérieure à la seconde.

### 4. `ft_write`

**Prototype :** `ssize_t ft_write(int fd, const void *buf, size_t count);`

**Man :** `man 2 write`

Cette fonction écrit `count` octets à partir du buffer `buf` dans le descripteur de fichier `fd`. Elle retourne le nombre d'octets écrits ou -1 en cas d'erreur.

### 5. `ft_read`

**Prototype :** `ssize_t ft_read(int fd, void *buf, size_t count);`

**Man :** `man 2 read`

Cette fonction lit `count` octets à partir du descripteur de fichier `fd` dans le buffer `buf`. Elle retourne le nombre d'octets lus ou -1 en cas d'erreur.

### 6. `ft_strdup`

**Prototype :** `char *ft_strdup(const char *s);`

**Man :** `man 3 strdup`

Cette fonction duplique une chaîne de caractères. Elle alloue de la mémoire pour une nouvelle chaîne, copie la chaîne source dans cette nouvelle mémoire, et retourne un pointeur vers la nouvelle chaîne. Si l'allocation échoue, elle retourne NULL.
