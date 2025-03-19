#include <stdio.h>
// Precaucion con los strings literales

void main(void)
{
	/* El string literal "Hola" se copia al arreglo de caracteres s1. 
	En cambio, el puntero s2 apunta al string literal "Chao". 
	Los string literales no se pueden modificar. Si intentamos 
	modificar un string literal, el programa se cae. */
	char s1[] = "Hola";
	char* s2 = "Chao";
	
	printf("%s %s\n", s1, s2); // No problema
	s1[0] = 'X';
	printf("%s %s\n", s1, s2); // Todavia OK
	// Si descomenta la siguiente linea el programa se queda pegado
	// s2[0] = 'X';
}