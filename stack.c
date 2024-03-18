#include "stack.h"
#include <stdlib.h>

// Initialisation de la pile
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->items = (StackItem*)malloc(sizeof(StackItem) * capacity);
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

// Suppression de la pile
void deleteStack(Stack* stack) {
    free(stack->items);
    free(stack);
}

// Ajoute un élément dans la pile
bool push(Stack* stack, StackItem item) {
    if (stack->top == stack->capacity - 1) return false;
    stack->items[++stack->top] = item;
    return true;
}

// Retire un élément de la pile
bool pop(Stack* stack, StackItem* item) {
    if (stack->top == -1) return false;
    *item = stack->items[stack->top--];
    return true;
}

// Voir l'élément au sommet de la pile sans le retirer
bool peek(const Stack* stack, StackItem* item) {
    if (stack->top == -1) return false;
    *item = stack->items[stack->top];
    return true;
}

// Vérifie si la pile est vide
bool isEmpty(const Stack* stack) {
    return stack->top == -1;
}
