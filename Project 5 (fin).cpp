// Project 5 (fin).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");
    int num;
    cout << "Введите число:";
    cin >> num;
    if (num > 0) 
    {
        _asm 
        {
            push num
            push 1
            call factorial //вызов процедуры
            jmp end
            factorial :
               mov eax, [esp + 4] 
               mov ebx, [esp + 8]
               mul ebx //умножение без знака eax*ebx
               dec ebx //-1
               cmp ebx, 1
               je exit //переход, если числа равны
               push ebx
               push eax
               call factorial
               pop ecx
               pop ecx
               ret
            exit :
               ret          //возвращает ближайшую процедуру
            end :
               mov num, eax
               pop ecx
               pop ecx
        }
    }
    return 0;
}


