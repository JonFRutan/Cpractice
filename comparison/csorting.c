int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    FILE *file = fopen(input, "r");
    if (file == NULL) {
        perror("Couldn't open file.");
    }

}