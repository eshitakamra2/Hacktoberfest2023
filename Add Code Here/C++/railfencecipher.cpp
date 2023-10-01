#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Define the encryption function
string railfence_encrypt(string plaintext, int key)
{
    int n = key;
    int len = plaintext.length();
    string ciphertext = "";
    int m = ceil((double)len / n);
    char rail[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rail[i][j] = '\0';
        }
    }
    int dir_down = false;
    int row = 0, col = 0;
    for (int i = 0; i < len; i++)
    {
        if (row == 0 || row == m - 1)
        {
            dir_down = !dir_down;
        }
        rail[row][col] = plaintext[i];
        col++;
        if (dir_down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rail[i][j] != '\0')
            {
                ciphertext += rail[i][j];
            }
        }
    }
    return ciphertext;
}

// Define the decryption function
string railfence_decrypt(string ciphertext, int key)
{
    int n = key;
    int len = ciphertext.length();
    string plaintext = "";
    int m = ceil((double)len / n);
    char rail[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rail[i][j] = '\0';
        }
    }
    int dir_down = false;
    int row = 0, col = 0;
    for (int i = 0; i < len; i++)
    {
        if (row == 0 || row == m - 1)
        {
            dir_down = !dir_down;
        }
        rail[row][col] = '*';
        col++;
        if (dir_down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }
    int index = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rail[i][j] == '*' && index < len)
            {
                rail[i][j] = ciphertext[index];
                index++;
            }
        }
    }
    dir_down = false;
    row = 0, col = 0;
    for (int i = 0; i < len; i++)
    {
        if (row == 0 || row == m - 1)
        {
            dir_down = !dir_down;
        }
        plaintext += rail[row][col];
        col++;
        if (dir_down)
        {
            row++;
        }
        else
        {
            row--;
        }
    }
    return plaintext;
}

// Example usage
int main()
{
    string plaintext;
    int key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    cin >> key;
    string ciphertext = railfence_encrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;
    string decrypted_message = railfence_decrypt(ciphertext, key);
    cout << "Decrypted message: " << decrypted_message << endl;
    return 0;
}
