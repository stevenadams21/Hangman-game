#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    char guessWords[][16] ={"troll", "goblin", "hive", "sword", "tank missile", "super suit", "warrior", "ninja","hidden message",
     "warlock","magician","worgs", "armored", "wolves"};
    int randomIndex = rand() %14;
    int i, fullrand, numberLives = 5, correctGuesses = 0, oldCorrect = 0;
    int lengthOfWord = strlen(guessWords[randomIndex]);
    int letterGuessed[8] = {0,0,0,0,0,0,0,0}, quitGame = 0;
    char guess[16];
    char letterEntered;






    while(correctGuesses < lengthOfWord)
    {
        printf("\nHangman word:");
        for(i = 0; i < lengthOfWord; i++)
        {
            if(letterGuessed[i]==1)
            {
                printf("%c", guessWords[randomIndex][i]);
            }
            else
            {
                printf("-");

            }
        }
        printf("\n");


        printf("Number correct so far %d\n", correctGuesses);
        printf("Enter a guess letter: \n");
        fgets(guess,16,stdin);
        if(strncmp(guess, "quit", 4)== 0)
        {
            quitGame = 1;
            break;

        }
        letterEntered = guess[0];
        printf("letterEntered: %c\n", letterEntered);
        oldCorrect = correctGuesses;
        for(i = 0; i < lengthOfWord; i++)
        {
            if(letterGuessed[i]==1)
            {
                continue;
            }
            if(letterEntered == guessWords[randomIndex][i])
            {
                letterGuessed[i]= 1;
                correctGuesses++;

            }

        }
        if(oldCorrect == correctGuesses)
        {
            numberLives--;
            printf("Sorry wrong guess\n");
            if(numberLives == 0)
            {

                break;

            }
        }
        else
        {
            printf("Correct guess, great!\n");

        }

    }

    if(quitGame == 1)
    {
        printf("\nThe user quit early\n");

    }
    else if(numberLives == 0)
    {

        printf("All out of lives, game over, the word was:  %s, try again next time\n", guessWords[randomIndex] );
    }
    else
    {
        printf("You win, congratulations\n");
    }
    return 0;
}
