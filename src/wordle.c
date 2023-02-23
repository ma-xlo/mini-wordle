#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define WORDS_COUNT 1604
#define ARRAY_SIZE  6
#define WORD_LENGTH 5
#define BLANK_SPACE ' '

char * genRandomWord(char * word){

    srand(time(NULL));
    int random = rand() % WORDS_COUNT;
    FILE *fp;
    char aux[7];

    fp = fopen("words-db.dat", "r");

    if (NULL == fp) 
        printf("File can't be opened\n");

    for(int i = 0; i <= random; i++) 
        fgets(aux, 7, fp);

    aux[strcspn(aux, "\n")] = 0;
    aux[0] = tolower(aux[0]);
    strcpy(word, aux);

    fclose(fp);

    return word;

}

int containsChar(char letter, char *word) {
    for(int i = 0; i < 5; i++) 
        if(letter == word[i])
            return 1;
    return 0;
}

void fillWithSpace(int row, int column, char arr[row][column]){
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < WORD_LENGTH; j++) {
            arr[i][j] = BLANK_SPACE;
        }   
    }
}

int main() {

    srand(time(NULL));
    char wordBank[5][6] = {"ultra", "pause", "equal", "sauce", "mouse"};
    char word[6]; 
    int alert = 0;
    
    printf("       Wordle\n");
    strcpy(word, genRandomWord(word));
    strcpy(word, wordBank[rand() % 5]);
    
    char guesses[6][30];
    char guess[30];
    int try = 0;

    fillWithSpace(6, 30, guesses);

    while (try <= 6) { 
        system("clear");
        printf("%s\n\n\n", word);
        printf("       Wordle\n");
        for(int i = 0; i < 6; i++ ) {
            for(int j = 0; j < 5; j++) {
                printf(" ");
                if(guesses[i][j] == word[j])
                    printf("\033[0;32m[%c]\033[0m", toupper(guesses[i][j]));
                else if(containsChar(guesses[i][j], word)) {
                    for(int k = 0; k < 5; k++) {
                        if(guesses[i][j] == word[k]) 
                            printf("\033[0;33m[%c]\033[0m", toupper(guesses[i][j]));
                    }
                }
                else
                    printf("\033[38;5;246m[%c]\033[0m", toupper(guesses[i][j]));

            }
            printf("\n");
        }  

        if(strcmp(guess, word) == 0) {
            printf("\n       You Win!\n\n");
            exit(0);
        }

        if(try == 6 && strcmp(guess, word) != 0) {
            printf("\n      You Lose!\n\n");
            exit(0);
        }

        if(alert == 1) {
            printf("   \033[91m Invalid word!\033[0m\n");
            alert = 0;
        }
        else {printf("\n");}

        printf("      Word: ");
        scanf("%s", guesses[try]);
        if(strlen(guesses[try]) != 5){
            for(int j = 0; j < 5; j++) 
                guesses[try][j] = BLANK_SPACE;
            alert = 1;
            continue;
        }
        
        strcpy(guess, guesses[try]);
        try++;
        fflush(stdin);
    }
    
    return 0;
}
