#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int size;  // numero de elementos en el stack en cada instante
    int data[MAXSIZE];
} stack;

/* Prototipo de funciones */
stack * make_stack(void);
void push(stack *sp, int a);
int pop(stack *sp);
void display_stack(stack *sp);
void destroy_stack(stack *sp);

int main(void)
{
    stack *s;
    int i, j, k;
    
    printf("Ejemplo de un stack\n");
    s = make_stack();
    printf("Stack vacio:\n");
    display_stack(s);
    printf("Stack con un elemento:\n");
    push(s, 42);
    display_stack(s);
    printf("Stack con varios elementos:\n");   
    push(s, 12);
    push(s, 34);
    push(s, 56);
    display_stack(s);
    j = s->size;
    for(i = 0; i<j; i++) {
        k = s->size;
        printf("Size: %d ; Pop: %d\n", k, pop(s));
    }
    return 0;
}


stack *make_stack(void)
{
    stack *sp = malloc(sizeof(stack));
    if(sp == NULL) {
          fputs("Error: no se puede asignar memoria", stderr);
          exit(1);
    } else {
        sp->size = 0;
        return sp;      
    }
}

void push(stack *sp, int a)
{
    if(sp->size == MAXSIZE) {
        fputs("Error: stack overflow", stderr);
        exit(1);
    } else {
        sp->data[sp->size++] = a;
    }
}


int pop(stack *sp)
{
    if(sp->size == 0) {
        fputs("Error: empty stack", stderr);
        exit(1);
    }
    return sp->data[--(sp->size)];    
}


void display_stack(stack *sp)
{
    int i;
    printf("-------\n");
    for(i = sp->size - 1; i >= 0; i--)
        printf("%d\n", sp->data[i]);
    printf("-------\n\n");
}