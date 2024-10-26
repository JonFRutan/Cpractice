#include "mercury.h"

int main() {
    printf("Welcome.\n");
    shellLoop();

}

void shellLoop() {
    char buffer[50];
    int status = 0;
    while (1) {
        buffer[0] = '\0';
        printf("> ");
        cleanInput(readInput(buffer, sizeof(buffer)));
        status = command_invoke(buffer);
        printf("%d", status);
        printf("\n");
    }
//    return 0;
}

// Reads input into the buffer. Initially the arguments were just char* buffer, however I added
// the size_t as a fix for an issue I saw occuring.
// More on this fix will be in mercury.txt
char* readInput (char* buffer, size_t bufferSize) {
    if (fgets(buffer, bufferSize, stdin) != NULL) {
        return buffer;
    } else {printf("Invalid Input.\n");}
}

// Reads through the input to see if every character is within the key (in the header file)
// Any character that is in the key is put into a temporary buffer to replace the original buffer.
// Characters not in the key are simply ignored.
void cleanInput (char* buffer) {
    if (buffer == NULL) {
        return;
    }
    char cleanBuffer[50];
    int j = 0;
    for (int i=0; buffer[i] != '\0'; i++) {
        if (strchr(key, buffer[i])) {
            cleanBuffer[j++] = buffer[i];
        }
    }
    cleanBuffer[j] = '\0';                                 //Null terminate end of string
    strcpy(buffer, cleanBuffer);
    return;
}

