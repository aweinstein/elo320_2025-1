#include <stdio.h>

void main(void)
{
	int a[10];
	int* p;  // Probar que pasa si usamos otro tipo de dato
	int i;
	
	p = a;
	//p = &a[0];
	// Mostrar la direccion de los elementos a
	for(i=0; i<10; i++)
		printf("a[%d] -> 0x%p \n", i, p++);
}