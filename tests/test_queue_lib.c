//
// Created by marcin on 13.12.2020.
//

#include "../libs/queue_lib.h"
#include "../unity/unity.h"
#include <string.h>

void test_push_to_stack_and_pop(void) {
    next_element *stack = NULL;
    optional result;
    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 5);
    push(&stack, 9);
    push(&stack, -18);
    result = pop(&stack);
    TEST_ASSERT_EQUAL_INT(-18, result.value);
    TEST_ASSERT_EQUAL(OK, result.status);

    result = pop(&stack);
    TEST_ASSERT_EQUAL_INT(9, result.value);
    TEST_ASSERT_EQUAL(OK, result.status);

    result = pop(&stack);
    TEST_ASSERT_EQUAL_INT(5, result.value);
    TEST_ASSERT_EQUAL(OK, result.status);

    result = pop(&stack);
    TEST_ASSERT_EQUAL_INT(3, result.value);
    TEST_ASSERT_EQUAL(OK, result.status);

    result = pop(&stack);
    TEST_ASSERT_EQUAL_INT(1, result.value);
    TEST_ASSERT_EQUAL(OK, result.status);

    result = pop(&stack);
    TEST_ASSERT_EQUAL(EMPTY, result.status);
    TEST_ASSERT_EQUAL(NULL, stack);
}

void test_enque_and_deque(void) {
    next_element *head = NULL;
    next_element *tail = NULL;
    optional result;
    result = deque(&head, &tail);
    TEST_ASSERT_EQUAL(EMPTY, result.status);

    enque(&head, &tail, 1);
    TEST_ASSERT_EQUAL_INT(1, tail->value);
    TEST_ASSERT_EQUAL_INT(1, head->value);
    TEST_ASSERT_EQUAL(NULL, tail->next);
    TEST_ASSERT_EQUAL(NULL, head->next);

    result = deque(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(1, result.value);

    enque(&head, &tail, 1);
    enque(&head, &tail, 2);
    TEST_ASSERT_EQUAL(tail, head->next);
    TEST_ASSERT_EQUAL(NULL, tail->next);
    TEST_ASSERT_EQUAL_INT(1, head->value);
    TEST_ASSERT_EQUAL_INT(2, tail->value);

    enque(&head, &tail, 3);
    TEST_ASSERT_EQUAL(tail, head->next->next);
    TEST_ASSERT_EQUAL(NULL, tail->next);
    TEST_ASSERT_EQUAL_INT(1, head->value);
    TEST_ASSERT_EQUAL_INT(2, head->next->value);
    TEST_ASSERT_EQUAL_INT(3, tail->value);

    result = deque(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(1, result.value);

    result = deque(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(2, result.value);

    result = deque(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(3, result.value);

    result = deque(&head, &tail);
    TEST_ASSERT_EQUAL(EMPTY, result.status);
}

void test_enque_and_deque_from_head_and_tail(void) {
    next_prev_element *head = NULL;
    next_prev_element *tail = NULL;
    optional result;

    result = deque_from_head(&head, &tail);
    TEST_ASSERT_EQUAL(EMPTY, result.status);

    result = deque_from_tail(&head, &tail);
    TEST_ASSERT_EQUAL(EMPTY, result.status);

    enque_next_prev(&head, &tail, 1);
    TEST_ASSERT_EQUAL_INT(1, tail->value);
    TEST_ASSERT_EQUAL_INT(1, head->value);
    TEST_ASSERT_EQUAL(NULL, tail->next);
    TEST_ASSERT_EQUAL(NULL, tail->prev);
    TEST_ASSERT_EQUAL(NULL, head->next);
    TEST_ASSERT_EQUAL(NULL, head->prev);

    result = deque_from_head(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(1, result.value);

    enque_next_prev(&head, &tail, 2);
    result = deque_from_tail(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(2, result.value);

    // HEAD value = 3
    enque_next_prev(&head, &tail, 3);
    enque_next_prev(&head, &tail, 4);
    enque_next_prev(&head, &tail, 5);
    enque_next_prev(&head, &tail, 6);
    enque_next_prev(&head, &tail, 7);
    // TAIL value = 7

    result = deque_from_head(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(3, result.value);
    TEST_ASSERT_EQUAL_INT(4, head->value);
    TEST_ASSERT_EQUAL_INT(5, head->next->value);

    result = deque_from_tail(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(7, result.value);
    TEST_ASSERT_EQUAL_INT(6, tail->value);
    TEST_ASSERT_EQUAL_INT(5, tail->prev->value);

    result = deque_from_head(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(4, result.value);
    TEST_ASSERT_EQUAL_INT(5, head->value);
    TEST_ASSERT_EQUAL_INT(6, tail->value);
    TEST_ASSERT_EQUAL_INT(5, tail->prev->value);
    TEST_ASSERT_EQUAL_INT(6, head->next->value);

    result = deque_from_tail(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(6, result.value);
    TEST_ASSERT_EQUAL_INT(5, tail->value);
    TEST_ASSERT_EQUAL_INT(5, head->value);

    result = deque_from_head(&head, &tail);
    TEST_ASSERT_EQUAL(OK, result.status);
    TEST_ASSERT_EQUAL_INT(5, result.value);
    TEST_ASSERT_EQUAL(NULL, head);
    TEST_ASSERT_EQUAL(NULL, tail);
}