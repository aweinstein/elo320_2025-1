#include <stdio.h>

void main()
{
    char* names[] = {"Juan", "Alejandro", "Valeria"};
    int i;
    int size;
    
    // Tamanio del arreglo
    size = sizeof(names) / sizeof(names[0]);
    for(i = 0; i < size; i++) {
        printf("%d -> %s \n", i + 1, *(names + i));
    }
}