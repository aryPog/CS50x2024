//#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if(argc != 2){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //honestamente falando isso deve ser top 10 bglh burro
    for (int i = 0; i < strlen(argv[1]); i++)
        if (isdigit(argv[1][i]) == 0)
            return 1;

    int casa = atoi(argv[1]);
    if(casa==0){
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char text[100];
    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);
    int len = strlen(text);
    char new_text[len];
    for(int i =0;i<len;i++){
        if((text[i]>=65&&text[i]<=90)||(text[i]>=97&&text[i]<=122)){
            for(int j=0;j<26;j++){
                if(text[i]==letters[j])
                    new_text[i]=letters[(j+casa)%26];
                else if(text[i]==LETTERS[j])
                    new_text[i]=LETTERS[(j+casa)%26];
            }
        }else
            new_text[i] = text[i];
    }
    printf("ciphertext: ");
    for(int i = 0;i<len;i++){
        printf("%c",new_text[i]);
    }
    printf("\n");

    return 0;
}
