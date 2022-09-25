#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // recieve command-line prompt from user
    if (argc < 2)
    {
        printf("Missing command line-argument\n");
        return 1;
    }
    if (argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
    }

    // store key as variable
    string key = argv[1];

    // work out substitution values
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isupper(key[i]))
        {
            key[i] = key[i] - 65;
        }
        else if (islower(key[i]))
        {
            key[i] = key[i] - 97;
        }
        else if (!isalpha(key[i]))
        {
            key[i] = key[i];
        }
    }

    // prompt user for plaintext
    string plaintext = get_string("Plaintext: ");

    //cipher text using substituted values
    int textlength = strlen(plaintext), keyplace = 0;
    int modulo = 26 - keyplace;
    char ciphertext[1000];
    for (int i = 0; i < textlength; i++)
    {
        // determine which char of key corresponds to plaintext
        if (isupper(plaintext[i]))
        {
            keyplace = plaintext[i] - 65;
            ciphertext[i] = (atoi(key) % modulo) + 65;
        }
        if (islower(plaintext[i]))
        {
            keyplace = plaintext[i] - 97;
            ciphertext[i] = (atoi(key) % modulo) + 97;
        }
        if (!isalpha(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
        }

        // output ciphertext
        printf("ciphertext: %s", ciphertext);
    }
    printf("\n");
    return 0;
}
