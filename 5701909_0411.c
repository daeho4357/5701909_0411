#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;


void init(StackType* sptr, int ofs) {
    sptr->data = (element*)malloc(sizeof(element) * ofs);
    sptr->top = -1;
    sptr->capacity = ofs;
}

int is_full(StackType* sptr) {
    if (sptr->top == sptr->capacity - 1) {
        sptr->capacity = sptr->capacity * 2;
        sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));
        return (sptr->data != NULL); // Return true if reallocation was successful
    }
    return 0; // Return false otherwise
}

int is_empty(StackType* sptr) {
    return (sptr->top == -1);
}

void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    sptr->top++;
    sptr->data[sptr->top] = item;
}

element pop(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "stack is empty\n");
        return -1;
    }
    return sptr->data[(sptr->top)--];
}

element peek(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "stack is empty\n");
        return -1;
    }
    return sptr->data[sptr->top];
}

void print_stack(StackType* sptr) {
    if (is_empty(sptr)) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= sptr->top; i++) {
            printf("%d ", sptr->data[i]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    StackType s;
    int rand_num;

    srand(time(NULL));

    init(&s, MAX_STACK_SIZE);

    for (int i = 0; i < 30; i++) {
        rand_num = rand() % 100 + 1;
        printf("Current rand_num : %d | %s\n", rand_num, (rand_num % 2 == 0) ? "Even" : "Odd");

        if (rand_num % 2 == 0) {
            if (!is_full(&s)) {
                push(&s, rand_num);
                printf("Push : %d\n", rand_num);
                print_stack(&s);
            }
            else {
                printf("Stack is FULL\n\n");
            }
        }
        else {
            if (!is_empty(&s)) {
                int pop_item = pop(&s);
                printf("Pop : %d\n", pop_item);
                print_stack(&s);

            }
            else {
                printf("Stack is empty\n\n");
            }
        }

        
    }

    free(s.data);

    return 0;
}

