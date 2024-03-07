//#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);
char *get_string(char *prompt);

int main(void)
{
    // Get input words from both players
    char *word1 = get_string("Player 1: ");
    char *word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score1 < score2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");

    free(word1);
    free(word2);
}

int compute_score(char *word)
{
    // TODO: Compute and return score for string
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int soma = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]) || islower(word[i]))
        {
            for (int j = 0; j < 32; j++)
            {
                if (word[i] == letters[j] || word[i] == LETTERS[j])
                {
                    // printf("aquie deu\n");
                    // printf("%c\n",word[i]);
                    soma += POINTS[j];
                    // printf("%i\n",soma);
                }
            }
        }
    }
    return soma;
}

char *get_string(char *prompt){
    char *input = malloc(100 * sizeof(char));

    printf("%s", prompt);
    scanf("%s",input);

    return input;
}