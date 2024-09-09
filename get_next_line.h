// get_next_line.h

// Include guard para evitar múltiplas inclusões
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

// Incluir as bibliotecas necessárias
#include <stdlib.h>
#include <unistd.h>

// Definir o protótipo da função get_next_line
char *get_next_line(int fd);

// Declare as funções auxiliares (que serão implementadas em get_next_line_utils.c)
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);

#endif

