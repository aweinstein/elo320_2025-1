#include <stdio.h>
// Copiar dos strings
// No podemos hacer s1=s2; (eso es copiar los punteros)

void strcpy_aw (char*, char*);

void main(void)
{
	char s1[20]="Hola", *s2="Chao";
	printf("%s %s\n", s1, s2);
	strcpy_aw(s1, s2);
	printf("%s %s\n", s1, s2);
}

// copiar b en a
void strcpy_aw(char* a, char* b)
{
	while((*a = *b) != '\0')
	{
		a++;
		b++;
	}
}