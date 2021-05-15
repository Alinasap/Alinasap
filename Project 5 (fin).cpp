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
        xor esi, esi //обнуляем, ESI -32 бита, индекс источника, сожержит текущий адрес элемента в цепочке-источнике; 
        mov esi, 1 //счетчик

        mov eax, f //факториал

        STEP1 :
        mul esi //eax * esi
            inc esi //инкрементируем счетчик
            cmp esi, a //если esi=a, то конец
            jng STEP1  // jng - прыгаем, если esi<=a
            mov a, eax
    }
    cout << a << endl;
    return 0;
}


