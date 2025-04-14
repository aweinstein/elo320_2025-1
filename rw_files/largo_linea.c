#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char line[MAX_LINE_LENGTH];
    int i;
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (input == NULL || output == NULL) {
        perror("Error opening file");
        return 1;
    }
    i = 0;
    while (fgets(line, sizeof(line), input)) {
        line[strcspn(line, "\n")] = '\0';
        size_t length = strlen(line);
        fprintf(output, "Linea %d, largo: %d.\n", ++i, length);
    }
    fclose(input);
    fclose(output);
    return 0;
}
