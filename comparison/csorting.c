//jfr
#include "csorting.h"

int main() {
    char input[100];               //Arbitrary cap for input length.
    printf("Welcome. Please provide a text file: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    //Clears the newline created by hitting "Enter"
    //strcspn is "String complement span". Here it finds the new-line character
    //and replaces it with a null-terminator.
    //strcspn returns the index of the provided character, since "input" is a string, we can
    //just call to that index to replace it.
    FILE *file = fopen(input, "r");
    if (file == NULL) {
        perror("Couldn't open file");
        return 1;
    }
    int line_count = count_lines(file);
    rewind(file);                                       //resets the file pointer
    line *lines = malloc(line_count * sizeof(line));
    parse_file(file, line_count, lines);
    //remove this section
    printf("File lines: \n");
    for (int i=0; i<line_count; i++) {
        printf("%s", lines[i].string);
    }
    //remove this section
    printf("Sorting...\n");
    fclose(file);
    free(lines);
}

//"dry run" of the file to count how many lines will be needed for mallocation.
int count_lines (FILE *file) {
    int line_count = 0;
    char buffer[50];               //Following with the arbitrary input cap.
    while (fgets(buffer, sizeof(buffer), file)) {
        line_count++;
    }
    return line_count;
}

//Reads in the lines from the file, then assigns every line to a 'line' object.
void parse_file(FILE *file, int line_count, line *lines) {
    char line_content[50];         //Each line is arbitrarily capped at 50 characters.
    int current_line = 0;
    while (fgets(line_content, sizeof(line_content), file) && current_line < line_count) {
        lines[current_line].ascii_value = get_line_value(line_content);
        strcpy(lines[current_line].string, line_content);
        current_line++;
    }
}

//converts every character into their representative ascii value, totals it, then returns the value.
unsigned int get_line_value(char *line) {
    unsigned int length = strlen(line);
    unsigned int line_value = 0;
    for (int i=0; i<length-1; i++) {
        line_value += (int)line[i];
    }  
    return line_value; 
}
