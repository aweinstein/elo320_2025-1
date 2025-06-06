#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("mobydick.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Determinar el largo del archivo
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Asignar memoria (+1 para caracter nulo)
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Asignacion de memoria fallo");
        fclose(file);
        return 1;
    }

    // Leer archivo en buffer
    size_t read_size = fread(buffer, 1, file_size, file);
    buffer[read_size] = '\0';  // Agrega caracter nulo

    // Finaliza la lectura
    fclose(file);

    // Mostrar los primeros mil caracteres
    printf("Primeros mil caracteres del archivo:\n");
    for(int i=0; i<1000; i++)
        putchar(buffer[i]);

    // Libera la memoria
    free(buffer);
    return 0;
}
