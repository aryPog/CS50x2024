//#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

char *get_string_v2(char *prompt);


int main(int argc, char *argv[])
{
    char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int e25 = -1;
    int frequency[256] = {0};
    // honestamente falando isso deve ser top 10 bglh burro
    for (int i = 0; i < strlen(argv[1]); i++)
    {

        if (isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        int c = tolower(argv[1][i]);
        frequency[c]++;
        if (frequency[c] > 1)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        e25++;
    }
    if (e25 != 25)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    char *casa = argv[1];

    char *text = get_string_v2("plaintext:");
    int len = strlen(text);
    char new_text[len];
    for (int i = 0; i < len; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == letters[j])
                    new_text[i] = tolower(casa[j]);
                else if (text[i] == LETTERS[j])
                    new_text[i] = toupper(casa[j]);
            }
        }
        else
            new_text[i] = text[i];
    }
    printf("ciphertext: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", new_text[i]);
    }
    printf("\n");

    free(text);
    return 0;
}


char *get_string_v2(char *prompt){
    char *input = malloc(100 * sizeof(char));

    printf("%s", prompt);

    fgets(input, MAX_LENGTH, stdin);

    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    return input;
}