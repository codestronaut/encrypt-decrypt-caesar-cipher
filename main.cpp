#include <iostream>
#include <string>
#include "caesar_cipher.h"

using namespace std;

// Create object for CaesarCipher class
// Scope: Global
CaesarCipher caesarChiper;

void encryptText(string text, int shift)
{
    caesarChiper.setPlainText(text);
    caesarChiper.setNShift(shift);
    string resultText = caesarChiper.encrypt();
    cout << "Result: " << resultText << endl;
}

void decryptText(string text, int shift)
{
    caesarChiper.setPlainText(text);
    caesarChiper.setNShift(shift);
    string resultText = caesarChiper.decrypt();
    cout << "Result: " << resultText << endl;
}

int main()
{

    string yourText, resultText;
    int shift, options;

    system("clear");
    cout << "Welcome To Encrypting Machine" << endl;
    cout << "Press any keys to continue..";
    cin.get();

/*
        Menu
    */
menu:
    system("clear");
    cout << "Choose one:" << endl;
    cout << "1. Encrypt my text" << endl;
    cout << "2. Decrypt my text" << endl;
    cout << "3. Exit" << endl;
    cout << "=> ";
    cin >> options;

    switch (options)
    {
    case 1:
        system("clear");
        cout << "Your Text: ";
        cin.ignore();
        getline(cin, yourText);
        cout << "Your Shift: ";
        cin >> shift;
        encryptText(yourText, shift);
        cout << "\nPress any key to continue" << endl;
        cin.ignore();
        cin.get();
        goto menu;
    case 2:
        system("clear");
        cout << "Your Text: ";
        cin.ignore();
        getline(cin, yourText);
        cout << "Your Shift: ";
        cin >> shift;
        decryptText(yourText, shift);
        cout << "\nPress any key to continue" << endl;
        cin.ignore();
        cin.get();
        goto menu;
    case 3:
        exit(0);
        break;
    default:
        cout << "There are no option match!" << endl;
        cin.ignore();
        cin.get();
        goto menu;
    }

    return 0;
}