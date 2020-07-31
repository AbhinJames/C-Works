// EncryptWithROT13ionDecryptionProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <sstream>
#include <math.h>

using namespace std;

void CheckInput();
string EncryptWithROT13(string a);
void EncryptionForNumbers(int num, int size);

int main()
{
    CheckInput();

    system("pause");
    return 0;
}

void CheckInput()
{
    int chooseInput = 0;

    cout << "--------WELCOME--------" << endl;
    cout << "Press 1 for Text Encryption" << endl;
    cout << "Press 2 for Number Encryption" << endl;
    cout << "-----------------------" << endl;

    cin >> chooseInput;

    if (chooseInput == 1)
    {
        string source, result, decrypted;

        cout << "Enter a text [ALPHABETICS ONLY]: " << flush;
        cin.ignore();
        getline(cin, source);

        result = EncryptWithROT13(source);
        cout << "Your encrypted text is : " << result << endl;

        CheckInput();
    }
    else if (chooseInput == 2)
    {
        int numInput;

        cout << "Enter password in digit [MAX = 5 DIGITS]: ";
        cin >> numInput;

        EncryptionForNumbers(numInput, 5);

        CheckInput();
    }
}

string EncryptWithROT13(string a)
{
    int z = a.length(), i = 0, key = 13;

    for (i = 0; i <= (z); i++)      //Rot13 Algorithm
    {
        if (a[i] < 91 && a[i] > 64)     //uppercase
        {
            if (a[i] < 78)
                a[i] = a[i] + key;
            else
                a[i] = a[i] - key;
        }
        if (a[i] < 123 && a[i] > 96)     //lowercase
        {
            if (a[i] < 110)
                a[i] = a[i] + key;
            else
                a[i] = a[i] - key;
        }
    }

    return a;
}

void EncryptionForNumbers(int num, int size)
{
    int temp, n = num, cube;
    int arr[5];

    for (int i = 0; i < size; i++)
    {
        temp = n % 10;
        n = n / 10;

        cube = pow(temp, 3);
        arr[i] = cube;
    }

    cout << "Your encrypted password is : ";

    for (int i = size-1; i >= 0; i--)
    {
        cout << arr[i];
    }

    cout << endl;
}
