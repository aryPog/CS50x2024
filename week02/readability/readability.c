/*
for some reason I need to explicitly link the math lib or else. . . 
    gcc -o readability readability.c -lm && ./readability
*/
//#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000

char *get_string_v2(char *prompt);

int main(void)
{

    int number_of_words = 1;
    int number_of_sentences = 0;
    int number_of_letters = 0;

    char *text = get_string_v2("Text: ");

    for(int i = 0;i<strlen(text);i++){
        if(text[i] == ' ')
            number_of_words++;
        if(text[i]=='?'||text[i]=='.'||text[i]=='!')
            number_of_sentences++;
        if(isalpha(text[i]))
            number_of_letters++;
    }

    double L = (double)number_of_letters / number_of_words *100.0;
    double S = (double)number_of_sentences / number_of_words *100.0;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index > 16)
        printf("Grade 16+\n");
    else if(index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %d\n", index);

    int debug = 0;
    if(debug){
        printf("text -> %s \n",text);
        printf("number_of_words -> %d\n",number_of_words);
        printf("number_of_sentences -> %d\n",number_of_sentences);
        printf("number_of_letters -> %d\n",number_of_letters);
        printf("L -> %lf\n",L);
        printf("S -> %lf\n",S);
        printf("index -> %d\n",index);
    }

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