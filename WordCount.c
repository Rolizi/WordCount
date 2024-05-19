#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <-c or -w> <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error: 无法打开文件.\n");
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        int charCount = 0;
        int c;
        while ((c = fgetc(file)) != EOF) {
            charCount++;
        }
        printf("字符数: %d\n", charCount);
    } else if (strcmp(argv[1], "-w") == 0) {
        int wordCount = 0;
        int inWord = 0; // Flag to track if currently in a word
        int c;
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\t' || c == '\n' || c == ',') {
                inWord = 0; // Not in a word
            } else if (inWord == 0) {
                wordCount++; // Found the start of a new word
                inWord = 1; // Now in a word
            }
        }
        printf("单词数: %d\n", wordCount);
    } else {
        printf("Error: Invalid option. Use -c or -w.\n");
    }

    fclose(file);
    return 0;
}