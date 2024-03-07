//#include <cs50.h>
#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    int n;
    do
    {
        n = get_int("type the height of the stair? ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (j <= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");
        for (int j = 0; j <= n; j++)
        {
            if (j <= i)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int get_int(char *prompt){
    int num;
    while(1){
        printf("%s",prompt);
        if (scanf("%d", &num) == 1){
            if (num >= 0)
                return num;
        }else{
            while (getchar() != '\n'); //clears input
        }
    }
}
