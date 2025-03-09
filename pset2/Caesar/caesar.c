#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to encrypt the text
string encrypt(string text, int key);

int main(int argc, string argv[])
{
    // Check if the command line argument count is 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert the key from string to integer
    int key = atoi(argv[1]);
    
    // Check if the key is a valid positive integer
    if (key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
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
string encrypt(string text, int key)
{
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            char offset = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - offset + key) % 26 + offset;
        }
    }
    return text;
}
