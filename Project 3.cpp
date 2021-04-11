// Project 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

static void UnsignedAdd(unsigned char a, unsigned char b)
{
    int isOverflow = 0; //Есть переполнение
    unsigned char result;
    _asm
    {
        mov al, a; // a - 1 байт, al - 1 байт
        mov bl, b;
        adc al, bl; //Сложение с переносом: al+bl+CF(флаг переноса)
        mov result, al;
        jnc STEP2  // перейти при отсутствии переноса
            jc STEP1;  // перейти при наличии переноса
    STEP1:
        mov isOverflow, 1; //Сообщаем, что есть переполнение
    STEP2:
    }
    cout << (isOverflow ? "overflow " : "no overflow ") << "unsigned " << (int)result << endl; //Если переполнение, то говорим "переполнение", иначе "нет переполнения"
}

static void SignedAdd(signed char a, signed char b) 
{
    int isOverflow = 0;
    char result;
    _asm
    {
        mov al, a;
        mov bl, b;
        adc al, bl;
        mov result, al;
        jno STEP2 // перейти при отсутствии переполнения
            jo STEP1; // перейти при наличии переполнения
    STEP1:
        mov isOverflow, 1;
    STEP2:
    }
    cout << (isOverflow ? "overflow " : "no overflow ") << "signed " << (int)result << endl;
}

int main()
{
	setlocale(0, "");
	int a, b;
	cout << "Введите первое число:\n";
	cin >> a;
	cout << "Введите второе число:\n";
	cin >> b;
	UnsignedAdd((unsigned char)a, (unsigned char)b);
	SignedAdd((signed char)a, (signed char)b);
	return 0;
}

