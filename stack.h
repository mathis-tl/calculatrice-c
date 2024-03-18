#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Définition d'une structure pour les éléments de la pile
typedef struct StackItem {
    char character;
    int value;
    int state;
} StackItem;

// Définition de la structure de la pile
typedef struct Stack {
    StackItem* items;
    int top;
    int capacity;
} Stack;

// Prototypes des fonctions de gestion de la pile
Stack* createStack(int capacity);
void deleteStack(Stack* stack);
bool push(Stack* stack, StackItem item);
bool pop(Stack* stack, StackItem* item);
bool peek(const Stack* stack, StackItem* item);
bool isEmpty(const Stack* stack);

#endif // STACK_H
