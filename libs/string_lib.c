//
// Created by marcin on 13.12.2020.
//

#include <string.h>
#include "string_lib.h"

/*
 * strcat - concatenate two strings
 * strchr - string scanning operation
 * strcmp - compare two strings
 * strcpy - copy a string
 * strlen - get string length
 * strncat - concatenate one string with part of another
 * strncmp - compare parts of two strings
 * strncpy - copy part of a string
 * strrchr - string scanning operation
 */


void reverse_words_in_a_string(char *src_str, char *target_str) {
    const size_t length = strlen(src_str);
    char *tmp = src_str + length - 1;
    size_t begin = length - 1;
    size_t end = length;
    while (*tmp--) {
        if ((strncmp(tmp, " ", 1) == 0) || (begin == 0)) {
            strncat(target_str, &src_str[begin], end - begin);
            if (begin > 0) strcat(target_str, " ");
            end = begin - 1;
        }
        begin--;
    }
}

