//
// Created by marcin on 13.12.2020.
//

#include "../libs/string_lib.h"
#include "../unity/unity.h"
#include <string.h>
#include <stdlib.h>

void test_reverse_words_in_a_string(void){
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char *reversed_str = calloc(strlen(str), sizeof(char));
    reverse_words_in_a_string(str, reversed_str);
    TEST_ASSERT_EQUAL_STRING("elit. adipiscing consectetur amet, sit dolor ipsum Lorem", reversed_str);
    free(reversed_str);
}