#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    double x;
    double y;

} Point;

typedef struct 
{
    Point *p;
    int numberOfPoints;

} Stack;


void initStack(Stack *stack)
{
    (*stack).p = malloc(sizeof(Point) * (*stack).numberOfPoints);
    
    for(int i = 0; i < (*stack).numberOfPoints; ++i){
        (*stack).p[i].x = 0;
        (*stack).p[i].y = 0;
    }
}

void push(Stack *stack, Point newPoint)
{
    (*stack).p[(*stack).numberOfPoints] = newPoint;

    ++(*stack).numberOfPoints;
}

Point top(Stack *stack)
{
    return (*stack).p[(*stack).numberOfPoints - 1];
}

Point pop(Stack *stack)
{
    Point last = top(stack);
    --(*stack).numberOfPoints;

    (*stack).p = realloc((*stack).p, sizeof(Point) * (*stack).numberOfPoints);

    return last;
}

double getDistance(Point a)
{
    return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

void printStack(Stack *stack)
{
    for(int i = 0; i < (*stack).numberOfPoints; ++i){
        printf("tasko (%0.1lf, %0.1lf) atstumas nuo pradzios tasko: %0.2lf\n",(*stack).p[i].x, (*stack).p[i].y, getDistance((*stack).p[i]));
    }
    printf("\n");
}

void destroyStack(Stack *stack)
{   
    free((*stack).p);
}

int main()
{
    Point newPoint;
    Stack points;

    points.numberOfPoints = 0;

    initStack(&points);
    
    newPoint.x = 5.0; newPoint.y = 0.0;
    push(&points, newPoint);

    newPoint.x = 15.0; newPoint.y = 0.1;
    push(&points, newPoint);

    newPoint.x = 8.6; newPoint.y = -5.3;
    push(&points, newPoint);
    
    newPoint.x = 4.3; newPoint.y = -10.0;
    push(&points, newPoint);

    newPoint.x = 5.5; newPoint.y = 4.5;
    push(&points, newPoint);

    printStack(&points);

    destroyStack(&points);

    return 0;
}