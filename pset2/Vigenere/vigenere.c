#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Function declarations
string encrypt(string text, string key);
char shift(char c, char k);

int main(int argc, string argv[])
{
    // Check if the command line argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }

    // Check if the key is valid (only alphabetic characters)
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./vigenere key\n");
            return 1;
        }
    }

    // Get the plaintext from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Function to encrypt the text
string encrypt(string text, string key)
{
    int n = strlen(text);
    int key_len = strlen(key);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            text[i] = shift(text[i], key[j % key_len]);
            j++;
        }
    }
    return text;
}

// Function to shift the character c by the character k
char shift(char c, char k)
{
    int key_shift = tolower(k) - 'a';
    if (isupper(c))
    {
        return (c - 'A' + key_shift) % 26 + 'A';
    }
    else
    {
        return (c - 'a' + key_shift) % 26 + 'a';
    }
}
