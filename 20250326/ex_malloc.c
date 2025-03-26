#include <stdio.h>
#include <stdlib.h>

int* give_me_mem(int);

int main()
{
	int *data;
	int i, largo = 10;
	data = give_me_mem(largo);
	for(i=0; i<largo; i++)
	{
		printf("%d -> %d \n", i, *(data+i));	
	}
	free(data);
	return 0;	
}

// Entrega un puntero a un arreglo de enteros de N elementos
// El arreglo se inicializa con la secuencia 0, 10, 20, ...
int* give_me_mem(int N)
{
	int* p;
	int i;
	p = malloc(N * sizeof(int)); // Debiesemos verificar si retorna NULL. Ver ex_malloc_check.c
	for(i=0; i<N; i++) 
	{
		*(p + i) = 10 * i;
	}
	return p;
}