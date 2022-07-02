#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int random = rand() % 4;
    char wordBank[4][6] = {"pause", "equal", "sauce", "mouse"};
    char word[6]; 
    strcpy(word, wordBank[random]);
    
    char guesses[5][30];
    char guess[30];
    int try = 0;
    char space[] = " ";
    
    //Populate the array with blank spaces
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            guesses[i][j] = *space;
        }   
    }

    while (try <= 5) { 
        system("cls||clear");
        printf("       Wordle\n");
        for(int i = 0; i < 5; i++ ) {
            for(int j = 0; j < 5; j++) {
                printf(" ");
                if(guesses[i][j] == word[j]){
                    printf("\033[0;32m[%c]\033[0m", toupper(guesses[i][j]));
                    //Yellow \033[0;33m
                } else {
                    printf("\033[38;5;246m[%c]\033[0m", toupper(guesses[i][j]));
                }
            }
            printf("\n");
        }
        if(strcmp(guess, word) == 0) {
            printf("\n       You Win!\n");
            exit(0);
        }
        if(try == 5 && strcmp(guess, word) != 0) {
            printf("\n      You Lose!\n");

            exit(0);
        }

        printf("\n     Word: ");
        scanf("%s", guesses[try]);
        strcpy(guess, guesses[try]);
        try++;
        fflush(stdin);
    }
    
    return 0;
}
