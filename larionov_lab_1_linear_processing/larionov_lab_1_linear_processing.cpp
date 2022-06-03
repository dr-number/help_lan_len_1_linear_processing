#pragma once
#include <iostream>
#include <Windows.h>
#include <random>
#include <regex>

#include "MyRandom.h"
#include "MyGeneral.h"
#include "MyInput.h"

#include "Task6.h"
#include "Task16.h"

int main()
{
    HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "Russian");

    SetConsoleTextAttribute(handleConsole, MyGeneral::White);

    cout << "Тема 1. Линейные вычислительные  процессы" << endl;

    bool isGo = true;
    string select;

    while (isGo)
    {

        cout << "\nВведите номер задачи" << endl;
        cout << "6) Вычислить v (объём) полого цилиндра" << endl;
        cout << "16) Вычислить площадь параллелограмма" << endl;
        cout << "Для выхода введите \"0\": ";

        select = MyGeneral::GetLine();
      
        //выбор задач
        if (select == "6") {
            Task6 task6 = *new Task6();
            task6.Init();
        }
        else if (select == "16") {
            Task16 task16 = *new Task16();
            task16.Init();
        } 
        else if (select == "0") {
            isGo = false;
        }
        else {
            SetConsoleTextAttribute(handleConsole, MyGeneral::Red);
            cout << "\nНекорректные данные!" << endl;
            SetConsoleTextAttribute(handleConsole, MyGeneral::White);
        }

    }
}

