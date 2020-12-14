//
// Created by marcin on 12.12.2020.
//
#include "unity/unity.h"

extern void test_reverse_words_in_a_string(void);
extern void test_push_to_stack_and_pop(void);
extern void test_enque_and_deque(void);
extern void test_enque_and_deque_from_head_and_tail(void);

void setUp(void){}
void tearDown(void){}

int main(void) {
    UnityBegin("tests/test_lib.c");
    RUN_TEST(test_reverse_words_in_a_string, 10);
    RUN_TEST(test_push_to_stack_and_pop, 27);
    RUN_TEST(test_enque_and_deque, 50);
    RUN_TEST(test_enque_and_deque_from_head_and_tail, 88);
    return(UnityEnd());
}