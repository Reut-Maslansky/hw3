#include <string.h>
#include <stdio.h>

#define LINE 256
#define WORD 30


//option a
void printContainWord(char *line, char *w) {
    if (strstr(line, w) != NULL) {
        printf("%s\n", line);
    }
}

//option b
void printSimilar(char *word, char *w) {
    char *copyWord = word;
    char *copyW = w;
    int bug = 0;
    int lenW = strlen(copyW);
    int lenWord = strlen(copyWord);

    if (lenW == lenWord || lenW == lenWord - 1) {
        int i = 0;
        while (bug < 2 && i < lenW) {
            if (*copyWord == *copyW) {
                copyWord++;
                copyW++;
            } else {
                bug++;
                copyWord++;
            }
            i++;
        }
        if (bug < 2)
            printf("%s\n", word);
    }
}


int main() {

    char input[WORD];
    char file[LINE];

    char inputFirstWord[WORD];
    char fileFirstWord[2];

    for (int i = 0; i < 2; i++) {
        if (fgets(inputFirstWord, WORD, stdin))
            strcat(fileFirstWord, inputFirstWord);
    }

    char *option = strtok(fileFirstWord, " ");
    char *search = option;
    option = strtok(NULL, "\n");
    char copyOption = *option;
    char copySearch[WORD];
    strcpy(copySearch, search);

    while (fgets(input, WORD, stdin)) {
        strcat(file, input);
    }

    //if a
    if (copyOption == 'a') {
        char *token;
        token = strtok(file, "\n");
        while (token != NULL) {
            printContainWord(token, copySearch);
            token = strtok(NULL, "\n");
        }
    }

    // if b
    if (copyOption == 'b') {

        char *word;
        word = strtok(file, " \t\r\n");
        while (word != NULL) {
            printSimilar(word, copySearch);
            word = strtok(NULL, " \t\r\n");
        }
    }
    return 0;
}