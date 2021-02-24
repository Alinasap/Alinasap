// Project 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

    void PrintBE(char* number, int bytes) //Число выводится слева-направо
    {
        cout << "Big-Endian:"; 
        for (int i = bytes - 1; i >= 0; i--)
        {
            for (int n = 0; n < 8; n++) 
            {
                cout << ((*(number + i) >> (7 - n)) & 1); //Байтовый сдвиг на i и побитовый сдвиг на 7-n
            }
        }
        cout << endl;
    }

    void PrintLE(char* number, int bytes) //Число выводится справа-налево
    {
        cout << "Little-Endian:";
        for (int i = 0; i < bytes; i++)
        {
            for (int n = 0; n < 8; n++)
            {
                cout << ((*(number + i) >> (7 - n)) & 1); //Байтовый сдвиг на i и побитовый сдвиг на 7-n
            }
        }
        cout << endl;
    }


    int main()
    {
        setlocale(0, "");
        cout << "Введите ваше число: ";
        int number;
        cin >> number;
        cout << "Для int:" << endl;
        PrintBE((char*)&number, 4); //Представляем память int, как указатель char
        PrintLE((char*)&number, 4);
        cout << "Для float:" << endl;
        float numFloat = (float)number;
        PrintBE((char*)&numFloat, 4); //Представляем память float, как указатель char
        PrintLE((char*)&numFloat, 4);
        cout << "Для double:" << endl;
        double numDouble = (double)number;
        PrintBE((char*)&numDouble, 8); //Представляем память double, как указатель char
        PrintLE((char*)&numDouble, 8);
        return 0;
    }
