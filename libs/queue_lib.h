//
// Created by marcin on 13.12.2020.
//

#ifndef C_TEST_QUEUE_LIB_H
#define C_TEST_QUEUE_LIB_H

typedef struct next_element {
    int value;
    struct next_element *next;
} next_element;

typedef struct next_prev_element {
    int value;
    struct next_prev_element *next;
    struct next_prev_element *prev;
} next_prev_element;

enum status_enum {OK, EMPTY};

typedef struct optional {
    int value;
    enum status_enum status;
} optional;

// LIFO (stack)
void push(next_element **ptr, int value);
optional pop(next_element **ptr);

// FIFO (queue)
void enque(next_element **head, next_element **tail, int value);
optional deque(next_element **head, next_element **tail);

// two directional queue (you can take elements from head and tail)
void enque_next_prev(next_prev_element **head, next_prev_element **tail, int value);
optional deque_from_tail(next_prev_element **head, next_prev_element **tail);
optional deque_from_head(next_prev_element **head, next_prev_element **tail);

#endif //C_TEST_QUEUE_LIB_H