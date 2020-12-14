//
// Created by marcin on 13.12.2020.
//
#include "queue_lib.h"
#include <stdlib.h>
#include <string.h>

void push(next_element **ptr, int value) {
    next_element *new_element = (next_element *) malloc(sizeof(next_element));
    new_element->value = value;
    new_element->next = *ptr;
    *ptr = new_element;
}

optional pop(next_element **ptr) {
    optional result = {0, OK};

    if (*ptr == NULL) {
        result.status = EMPTY;
    } else {
        next_element *old_ptr = *ptr;
        *ptr = (*ptr)->next;
        result.value = old_ptr->value;
        free(old_ptr);
    }

    return result;
}

void enque(next_element **head, next_element **tail, int value) {
    next_element *new_element = (next_element *) malloc(sizeof(next_element));
    new_element->value = value;
    new_element->next = NULL;
    if (*head == NULL) {
        // Create first next_element if queue is empty
        *head = new_element;
    } else {
        // add new next_element to the end
        (*tail)->next = new_element;
    }
    *tail = new_element;
}

optional deque(next_element **head, next_element **tail) {
    optional result = {0, OK};

    if (*head == NULL) {
        result.status = EMPTY;
    } else {
        next_element *old_head = *head;
        if (*(tail) == *(head)) {
            // If we take off the last next_element, we must also to modify
            // the head pointer
            (*head)->next = NULL;
            *tail = NULL;
        }
        *head = (*head)->next;
        result.value = old_head->value;
        free(old_head);
    }

    return result;
}

void enque_next_prev(next_prev_element **head, next_prev_element **tail, int value) {
    next_prev_element *new_element = (next_prev_element *) malloc(sizeof(next_prev_element));
    new_element->value = value;
    new_element->next = NULL;
    if (*head == NULL) {
        // Create first next_element if queue is empty
        new_element->prev = NULL;
        *head = new_element;
    } else {
        // add new next_element to the end
        new_element->prev = *tail;
        (*tail)->next = new_element;
    }
    *tail = new_element;
}

optional deque_from_head(next_prev_element **head, next_prev_element **tail) {
    optional result = {0, OK};
    if (*head == NULL) {
        result.status = EMPTY;
    } else {
        next_prev_element *old_head = *head;
        if (*(tail) == *(head)) {
            (*head)->next = NULL;
            *tail = NULL;
        }
        *head = (*head)->next;
        result.value = old_head->value;
        free(old_head);
    }
    return result;
}

optional deque_from_tail(next_prev_element **head, next_prev_element **tail) {
    optional result = {0, OK};
    if (*tail == NULL) {
        result.status = EMPTY;
    } else {
        next_prev_element *old_tail = *tail;
        if (*(tail) == *(head)) {
            // taking last element
            (*tail)->prev = NULL;
            *head = NULL;
        }
        *tail = (*tail)->prev;
        result.value = old_tail->value;
        free(old_tail);
    }
    return result;
}