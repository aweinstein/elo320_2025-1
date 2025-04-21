#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int read;
    int write;
    int n; // Numero actual de elementos en el buffer
    int size; // Largo total del buffer
    int *data;
} buffer;

buffer * make_buffer(int size);
int get_buffer(buffer *b);
void put_buffer(buffer *b, int a);
int is_empty_buffer(buffer *b);
int is_full_buffer(buffer *b);
void display_buffer(buffer *b);
void destroy_buffer(buffer *b);

int main(void)
{
    buffer *b;
    int i;
    
    printf("Ejemplo de buffer circular\n");
    b = make_buffer(10);
    put_buffer(b, 12); // Falta verificar que el buffer no este lleno!
    put_buffer(b, 34); // Falta verificar que el buffer no este lleno!
    display_buffer(b);
    for(i=0; i<10; i++) {
        if(!is_full_buffer(b))
            put_buffer(b, i);
        else
            printf("Buffer lleno, no se pudo escribir %d\n", i);
    }
    display_buffer(b);
    printf("Leamos algunos datos del buffer\n");
    printf("Dato sacado del buffer: %d \n", get_buffer(b)); // Falta verificar que el buffer tenga datos!
    printf("Dato sacado del buffer: %d \n", get_buffer(b)); // Falta verificar que el buffer tenga datos!
    display_buffer(b);
    for(i=0; i<10; i++) {
        if(!is_empty_buffer(b))
            printf("Dato sacado del buffer: %d \n", get_buffer(b));
        else
            printf("El buffer esta vacio \n");
    }
    display_buffer(b);
    
    destroy_buffer(b);
    printf("Bye\n");
    return 0;
}

buffer * make_buffer(int size)
{
    buffer *b = malloc(sizeof(buffer)); // Falta manejar el caso en que malloc retorna NULL
    b->read = 0;
    b->write = 0;
    b->n = 0;
    b->size = size;
    b->data = malloc(size * sizeof(int)); // Falta manejar el caso en que malloc retorna NULL
    return b; 
}

// Quien llama a la funcion es responsable de verificar que el buffer no este vacio
// No es la mejor de las ideas
int get_buffer(buffer *b)
{
    int d;
    d = b->data[b->read];
    b->read = (b->read + 1) % b->size;
    b->n--;
    return d;
}


void put_buffer(buffer *b, int d)
{
    b->data[b->write] = d;
    b->write = (b->write + 1) % b->size;
    b->n++;   
}

int is_empty_buffer(buffer *b)
{
    return (b->n == 0);    
}


int is_full_buffer(buffer *b)
{
    return (b->n == b->size);    
}

void display_buffer(buffer *b)
{
    int i, cursor;
    cursor = b->read; // Lo copiamos para no alterar el valor de read
    for(i=0; i < b->n; i++) {
        printf("%d ", b->data[cursor]);
        cursor = (cursor + 1) % b->size;
    }
    printf("\n");
}

void destroy_buffer(buffer *b) {
    free(b->data);
    free(b);
}

