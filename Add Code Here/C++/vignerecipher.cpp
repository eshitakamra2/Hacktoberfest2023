#include <iostream>
#include <cstring>
#include <cctype>

// Function to perform Vigenere Cipher encryption
void vigenereEncrypt(char plaintext[], char key[], char ciphertext[])
{
    int i, j;
    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);
    for (i = 0, j = 0; i < plaintextLen; i++, j++)
    {
        if (j == keyLen)
        {
            j = 0;
        }
        int p = toupper(plaintext[i]) - 'A';
        int k = toupper(key[j]) - 'A';
        int c = (p + k) % 26;
        ciphertext[i] = c + 'A';
    }
    ciphertext[i] = '\0';
}

// Function to perform Vigenere Cipher decryption
void vigenereDecrypt(char ciphertext[], char key[], char plaintext[])
{
    int i, j;
    int ciphertextLen = strlen(ciphertext);
    int keyLen = strlen(key);
    for (i = 0, j = 0; i < ciphertextLen; i++, j++)
    {
        if (j == keyLen)
        {
            j = 0;
        }
        int c = toupper(ciphertext[i]) - 'A';
        int k = toupper(key[j]) - 'A';
        int p = (c - k + 26) % 26;
        plaintext[i] = p + 'A';
    }
    plaintext[i] = '\0';
}

int main()
{
    char plaintext[100], key[100], ciphertext[100];

    // Input the plaintext and the key
    std::cout << "Enter the plaintext: ";
    std::cin >> plaintext;
    std::cout << "Enter the key: ";
    std::cin >> key;

    // Encrypt the plaintext using the key
    vigenereEncrypt(plaintext, key, ciphertext);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    // Decrypt the ciphertext using the key
    vigenereDecrypt(ciphertext, key, plaintext);
    std::cout << "Plaintext: " << plaintext << std::endl;

    return 0;
}
