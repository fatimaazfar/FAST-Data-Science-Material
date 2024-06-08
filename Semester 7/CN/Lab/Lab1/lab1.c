#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    FILE *inputFile, *outputIntegersFile, *outputNonAlphabetFile, *outputInvertedFile;
    
    // Open the input file for reading
    inputFile = fopen("Input_File.txt", "r");
    
    if (inputFile == NULL) {
        printf("Error opening Input_File.txt.\n");
        return 1;
    }

    // Open the output files for writing
    outputIntegersFile = fopen("Integers_Output_File.txt", "w");
    outputNonAlphabetFile = fopen("Non_Alphabet_Output_File.txt", "w");
    outputInvertedFile = fopen("Inverted_Output_File.txt", "w");

    if (outputIntegersFile == NULL || outputNonAlphabetFile == NULL || outputInvertedFile == NULL) {
        printf("Error creating output files.\n");
        return 1;
    }

    char word[1000];

    while (fscanf(inputFile, "%s", word) != EOF) {
        printf("%s ", word);

        int isInteger = 1;
        int isNonAlphabet = 1;

        for (int i = 0; word[i] != '\0'; i++) {
            if (!isdigit(word[i])) {
                isInteger = 0;
            }
            if (isalpha(word[i])) {
                isNonAlphabet = 0;
                break;
            }
        }

        if (isInteger) {
            fprintf(outputIntegersFile, "%s\n", word);
        }

        if (isNonAlphabet) {
            fprintf(outputNonAlphabetFile, "%s\n", word);
        }

        if (strpbrk(word, "aeiouAEIOU") != NULL) {
            reverseString(word);
        }

        fprintf(outputInvertedFile, "%s ", word);
    }

    // Close all files
    fclose(inputFile);
    fclose(outputIntegersFile);
    fclose(outputNonAlphabetFile);
    fclose(outputInvertedFile);

    return 0;
}