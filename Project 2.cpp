// Project 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 10;
    int c = 44;
    int d = 13;
    int e = 2;
    int x;
    int sum;
    int product;
    int difference;
 
    __asm
    {   
        //сложение:
        mov eax, a;  //eax - 4 байта, int - 4 байта
        add eax, b;
        mov sum, eax;
        //умножение:
        mov eax, sum;
        mul c;
        mov product, eax;
        //вычитание:
        mov eax, product;
        sub eax, d;
        mov difference, eax;
        //деление:
        mov eax, difference;
        div e;
        mov x, eax;
    }

    cout << x;
}
