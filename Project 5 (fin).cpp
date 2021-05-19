// Project 5 (fin).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a;
    int f = 1;
    cin >> a;

    __asm
    {
        mov ecx, 1 //счетчик цикла

        mov eax, f //факториал

        STEP1 :
         mul ecx //eax * ecx
         inc ecx //инкрементируем счетчик
         cmp a, ecx
            jae STEP1; // прыгаем, если ecx<=a
         mov a, eax
    }
    cout << a << endl;
    return 0;
}


