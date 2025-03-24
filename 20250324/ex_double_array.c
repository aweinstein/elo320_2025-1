#include <stdio.h>
#include <string.h>

void foo(char* [], int);
void bar(char**, int);

void main()
{
	char* cosas[] = {"auto", "pelota", "patin"};	
	int n = sizeof(cosas) / sizeof(cosas[0]);
	foo(cosas, n);
	printf("\n");
	bar(cosas, n);
}

void foo(char* x[], int size)
{
	int i;
	
	for(i=0; i<size; i++) // Hago trampa con ese tres... usar sizeof
	{
		printf("%s ", x[i]);
		//Tambine podemos escribir printf("%s ", *(x + i));
	}
	printf("\n");
}

void bar(char** x, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%s -> # caracteres %d\n", *(x + i), strlen(*(x + i)));
	}
}