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
        mov ecx, 0; // обнуляем счетчик цикла
        mov ecx, 1 

        mov eax, f //факториал

        STEP1 :
         mul ecx //eax * ecx
         inc ecx //инкрементируем счетчик
         cmp ecx, a //если ecx=a, то конец
         jng STEP1  // jng - прыгаем, если ecx<=a
         mov a, eax
    }
    cout << a << endl;
    return 0;
}


