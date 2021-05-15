// Project 4.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

    
    int main() 
    {
        setlocale(0, "");
        char inMessage[100] = "Кабан нажал на баклажан";
        char reMessage[100];
        __asm
        {
            mov ecx, 0; // счетчик цикла
        BeginPush:
            mov al, [inMessage + ecx]; // Кидаем в регистр один символ
            push eax; // Кидаем в стек
            inc ecx; // Инкремент для доступа к следующему элементу
            cmp[inMessage + ecx], 0; // Сравниваем длину строки c 0
            je EndPush; // Если 0, то идем к EndPush
            jmp BeginPush; // Если не 0, то повторяем
        EndPush:
            mov ebx, 0; // Счетчик цикла
        BeginPop:
            pop eax; // Достаем символы из стека
            mov[reMessage + ebx], al; // Получаем из регистра один символ
            inc ebx
                cmp ecx, ebx
                je EndPop
                jmp BeginPop
                EndPop:
            mov[reMessage + ebx], 0
        }

        cout << reMessage;
	    return 0;
    }

