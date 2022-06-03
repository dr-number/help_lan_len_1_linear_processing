#pragma once
#include <iostream>
#include <Windows.h>
#include <regex>

#include "MyRandom.h"
#include "MyGeneral.h"
#include "MyInput.h"


class Task6 {

private:
    const int MIN = MyRandom::MIN_RANDOM;
    const int MAX = 100;

    //вычисляет объём полого цилиндра
    double printVolume(double h, double r1, double r2) {

        double square1 = MyGeneral::Round(r1 * r1);
        double square2 = MyGeneral::Round(r2 * r2);

        double differenceSquare = MyGeneral::Round(square1 - square2);
        double result = MyGeneral::Round(PI * h * differenceSquare);

        string strH = MyGeneral::RoundStr(h);

        cout << "v = ПИ * h (r1^2 - r2^2)" << endl;
        cout << "v = " << PI << " * " << strH << " * (" << fixed << MyGeneral::RoundStr(r1) << "^2 - " << fixed << MyGeneral::RoundStr(r2) << "^2)" << endl;

        cout << "v = " << PI << " * " << strH << " * (" << fixed << MyGeneral::RoundStr(square1) << " - " << fixed << MyGeneral::RoundStr(square2) << ")" << endl;
        cout << "v = " << PI << " * " << fixed << strH << " * " << fixed << MyGeneral::RoundStr(differenceSquare) << endl;

        cout << "v = " << fixed << MyGeneral::RoundStr(result) << endl;
        return result;
    }


public:
    void Init() { //взаимодействие с пользователем (ввод-вывод информации)

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, MyGeneral::White);

        cout << "\nВычислить v (объём) полого цилиндра\n";
        cout << "высотой h\n";
        cout << "внешним радиусом r1\n";
        cout << "внутренним радиусом r2\n\n";

        cout << "По формуле: v = ПИ * h (r1^2 - r2^2)\n\n";


        double r1, r2, h;

        MyRandom myRandom = *new MyRandom();

        if (myRandom.isRandomData()) {
            h = myRandom.GetRandom(MIN, MAX);

            while (true) {
                r2 = myRandom.GetRandom(MIN, MAX) - 1;
                r1 = myRandom.GetRandom(r2, MAX);

                if (r1 > r2)
                    break;
            }
        }
        else {
            MyInput myInput = *new MyInput();

            h = myInput.InputData("Введите высоту цилиндра: ", MIN, MAX);

            while (true) {
                SetConsoleTextAttribute(handle, MyGeneral::White);

                r1 = myInput.InputData("Введите внешний радиус цилиндра: ", MIN, MAX);
                r2 = myInput.InputData("Введите внутренний радиус цилиндра: ", MIN, MAX);

                if (r1 <= r2) {
                    SetConsoleTextAttribute(handle, MyGeneral::Red);
                    cout << endl << "Внешний радиус цилиндра должен быть больше внутреннего!" << endl;
                }
                else
                    break;
            }

        }

        h = MyGeneral::Round(h);
        r1 = MyGeneral::Round(r1);
        r2 = MyGeneral::Round(r2);

        SetConsoleTextAttribute(handle, MyGeneral::Yellow);
        cout << endl << "Полученные данные:" << endl;
        cout << "Высота цилиндра (h): " << MyGeneral::RoundStr(h) << endl;
        cout << "Внешний радиус цилиндра (r1): " << MyGeneral::RoundStr(r1) << endl;
        cout << "Внутренний радиус цилиндра (r2): " << MyGeneral::RoundStr(r2) << endl << endl;


        SetConsoleTextAttribute(handle, MyGeneral::Green);
        printVolume(h, r1, r2);

        SetConsoleTextAttribute(handle, MyGeneral::White);

    }

};

