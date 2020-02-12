#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <iostream>
#include <string>
using namespace std;

class CaesarCipher
{
private:
    // Create 2 variables
    // plainText for store user text for encrypt
    // nShift for store integer value for the shift
    string plainText;
    int nShift;

public:
    // Setter
    void setPlainText(string text);
    void setNShift(int shift);

    // encrypt and decrypt function
    string encrypt();
    string decrypt();
};

/*

Setter

*/
void CaesarCipher::setPlainText(string text)
{
    plainText = text;
}

void CaesarCipher::setNShift(int shift)
{
    nShift = shift;
}

/* 
    Encript Function
    This function has two input. First is string, and second is s (shift)
    This function will return new string that has encrypted 
*/
string CaesarCipher::encrypt()
{
    // Create a blank string
    string encrypted_string = "";

    // Create loop start from 0 until length of the character in the text
    for (int i = 0; i < plainText.length(); i++)
    {
        // Enrypting all the character of the string

        /* 
            If branch is for uppercase string 
            and else branch is for lowercase string 
        */
        if (isupper(plainText[i]))
        {
            // 65 mean that we use the uppercase letter (BASE ON ASCII TABLE)
            encrypted_string += char(int(plainText[i] + nShift - 65) % 26 + 65);
        }
        else
        {
            // 97 mean that we user the lowercase letter (BASE ON ASCII TABLE)
            encrypted_string += char(int(plainText[i] + nShift - 97) % 26 + 97);
        }
    }

    // Return new string
    return encrypted_string;
}

/* 
    Decrypt Function
    This function has two input. First is string, and second is s (shift)
    This function will return new string that has decrypted 
*/
string CaesarCipher::decrypt()
{
    // Create a blank string
    string decrypted_string = "";

    // Create loop start from 0 until length of the character in the text
    for (int i = 0; i < plainText.length(); i++)
    {
        // Derypting all the character of the string

        /* 
            If branch is for uppercase string 
            and else branch is for lowercase string 
        */
        if (isupper(plainText[i]))
        {
            // 65 mean that we use the uppercase letter (BASE ON ASCII TABLE)
            decrypted_string += char(int(plainText[i] - nShift - 65) % 26 + 65);
        }
        else
        {
            // 97 mean that we user the lowercase letter (BASE ON ASCII TABLE)
            decrypted_string += char(int(plainText[i] - nShift - 97) % 26 + 97);
        }
    }

    return decrypted_string;
}
#endif // CAESAR_CIPHER_H