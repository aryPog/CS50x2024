//#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int get_int(char *prompt);
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    // printf("%i\n",cents);
    //  Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("write cents: ");
    }
    while (cents < 1);
    return cents;
}

int calculate_quarters(int cents)
{
    int c = 0;
    while (cents >= 25)
    {
        cents -= 25;
        c++;
    }
    return c;
}

int calculate_dimes(int cents)
{
    int c = 0;
    while (cents >= 10)
    {
        cents -= 10;
        c++;
    }
    return c;
}

int calculate_nickels(int cents)
{
    int c = 0;
    while (cents >= 5)
    {
        cents -= 5;
        c++;
    }
    return c;
}

int calculate_pennies(int cents)
{
    int c = 0;
    while (cents >= 1)
    {
        cents -= 1;
        c++;
    }
    return c;
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