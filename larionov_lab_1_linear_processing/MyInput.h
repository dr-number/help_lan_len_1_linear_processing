#pragma once
#include <iostream>
#include <Windows.h>
#include <regex>

#include "MyGeneral.h"

using namespace std;

class MyInput {

public:

    //проверка является ли число дробным или целым
    bool isDouble(string str) {
        return regex_match(str, regex("^[-]?[0-9]*?,?[0-9]*"));
    }

    //запрашивает у пользователя число (до тех пор, пока не будут введены корректные данные)
    double InputData(string text, int min, int max, int defaultValue = -1) {

        string xStr = "";
        double result = 0;
        bool isNumber = true;

        HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        while (true) {

            SetConsoleTextAttribute(handleConsole, MyGeneral::White);
            cout << text;

            xStr = MyGeneral::GetLine();

            if (xStr == "" && defaultValue != -1)
                return defaultValue;


            try {
                result = stod(xStr.c_str());
                isNumber = true;
            }
            catch (...) {
                isNumber = false;
            }

            if (!(isNumber && isDouble(xStr))) {
                SetConsoleTextAttribute(handleConsole, MyGeneral::Red);
                cout << endl << xStr + " - не число!" << endl << endl;
            }
            else if (result > max || result < min) {
                SetConsoleTextAttribute(handleConsole, MyGeneral::Red);
                cout << endl << "Число должно лежать в промежутке [" << min << "; " << max << "]!" << endl << endl;
            }
            else
                break;
        }

        return result;
    }

};

