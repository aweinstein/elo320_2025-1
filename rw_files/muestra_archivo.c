#include <stdio.h>

int main() {
    char ch;
    FILE *file = fopen("ejemplo.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
