#include <stdio.h>
#include <stdlib.h>

/*sveikųjų skaičių stekas ir funkcijos dirbti su jais*/

typedef struct 
{
    int *array;
    int size;

} Stack;

void initStack(Stack *stack)
{
    (*stack).array = malloc((*stack).size * sizeof(int));

    for(int i = 0; i < (*stack).size; ++i){
        (*stack).array[i] = 0;
    }
}

void printStack(Stack *stack)
{
    for(int i = 0; i < (*stack).size; ++i){
        printf("%d ", (*stack).array[i]);
    }
    printf("\n");
}

int getStackSize(Stack *stack)
{
    return (*stack).size;
}

void push(Stack *stack, int value)
{
    (*stack).array[(*stack).size] = value;
    ++(*stack).size;
}

int top(Stack *stack)
{
    if(stack == NULL){
        return 0;
    }

    return (*stack).array[(*stack).size - 1];
}

int pop(Stack *stack)
{
    int last = top(stack);
    (*stack).array[(*stack).size - 1] = 0;
    --(*stack).size;

    (*stack).array = realloc((*stack).array, (*stack).size * sizeof(int));

    return last;
}

void destroyStack(Stack *stack)
{   
    free((*stack).array);
}

int main()
{

    return 0;
}