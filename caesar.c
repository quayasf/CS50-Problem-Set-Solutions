// CS50 Caesar Solution
// My solution for the week 2 problem set

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{

    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        printf("Ciphertext: ");
        for (int j = 0; j < strlen(plaintext); j++)
        {
            printf("%c", rotate(plaintext[j], key));
        }
        printf("\n");
    }
}

bool only_digits(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length;  i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char a, b;

    if (isalpha(c))
    {
        if (isupper(c))
        {
            a = c - 65;
            b = (a + n)%26;
            c = b + 65;
        }
        else if (islower(c))
        {
            a = c - 97;
            b = (a + n)%26;
            c = b + 97;
        }
        return c;
    }
    else
    {
        return c;
    }
}
