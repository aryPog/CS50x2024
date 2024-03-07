//#include <cs50.h>
#include <stdio.h>

long get_long(char *prompt);
long checkSum(long n);
long whatType(long n);
long rightSize(long n);


int main(void)
{
    long n;
    do
    {
        n = get_long("crd Number: ");
    }
    while (n < 1);

    int size = rightSize(n);
    int valid = checkSum(n);
    // printf("%i\n",valid);
    if (valid && size)
    {
        whatType(n);
    }
    else
    {
        printf("INVALID\n");
    }
}
long rightSize(long n)
{
    int c = 0;
    do
    {
        n /= 10;
        c++;
    }
    while (n > 0);
    if (c < 13 || c > 16)
    {
        return 0;
    }
    else if (c == 14)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
long checkSum(long n)
{
    long a = 0;
    long b = 0;
    long c = 0;
    long d = 0;
    while (n > 0)
    {
        b = b + (n % 10);
        // printf("b: %li\n",b);
        n = n / 10;
        if (n % 10 * 2 >= 10)
        {
            c = n % 10 * 2;
            // printf("as%li \n",c);
            while (c > 0)
            {
                d += c % 10;
                // printf("%li\n",d);
                c /= 10;
            }
            a = a + d;
            d = 0;
        }
        else
        {
            a = a + (n % 10 * 2);
        }
        // printf("a: %li\n",a);
        // printf("b: %li\n",b);
        n = n / 10;
        // printf("N: %li\n",n);
    }
    int r = a + b;
    // printf("%i\n",r);
    // return r;
    if (r % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

long whatType(long n)
{
    long m = n;
    int c = 0;
    do
    {
        n /= 10;
        c++;
    }
    while (n > 0);

    int cc = c;
    long z = 0;
    int zx = 0;
    while (cc > 0)
    {
        if (cc <= 1)
        {
            zx = m % 10;
        }
        if (cc <= 1 && m % 10 == 4)
        {
            z = m % 10;
        }
        else if (cc <= 2)
        {
            z = z + (m % 10);
        }
        m /= 10;
        cc--;
    }

    // printf("%i\n",zx);
    // printf("%li\n",z);
    char *result = "";
    if (c == 15 && (z == 7 || z == 10) && (zx % 10 == 3))
    {
        result = "AMEX\n";
    }
    else if ((c == 13 || c == 16) && z == 4)
    {
        result = "VISA\n";
    }
    else if (c == 16 && (z == 6 || z == 7 || z == 8 || z == 9 || z == 10) && (zx % 10 == 5))
    {
        result = "MASTERCARD\n";
    }
    else
    {
        result = "INVALID\n";
    }

    return printf("%s", result);
}

long get_long(char *prompt){
    long num;
    while(1){
        printf("%s",prompt);
        if (scanf("%ld", &num) == 1){
            if (num >= 0)
                return num;
        }else{
            while (getchar() != '\n'); //clears input
        }
    }
}
