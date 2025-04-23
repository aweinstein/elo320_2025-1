#include <stdio.h>

// Calcular el largo de un string
// Solo para el ejemplo, se puede usar strlen en string.h

int strlen_aw(char*);

int main(void)
{
    char msg[] = "Hola"; // No puedo usar mas de cuatro caracteres despues
    char* nombre = "Valentina"; // Podria crecer
    printf("Largo de %s es %d\n", msg, strlen_aw(msg));
    printf("Largo de %s es %d\n", nombre, strlen_aw(nombre));
    printf("Caracter %d de nombre: %c", 3, *(nombre+3));
}

int strlen_aw(char* s)
{
    int n;
    
    for(n=0; *s != '\0'; s++)
        n++;
    return n;
}