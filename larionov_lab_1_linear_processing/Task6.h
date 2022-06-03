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

    //��������� ����� ������ ��������
    double printVolume(double h, double r1, double r2) {

        double square1 = MyGeneral::Round(r1 * r1);
        double square2 = MyGeneral::Round(r2 * r2);

        double differenceSquare = MyGeneral::Round(square1 - square2);
        double result = MyGeneral::Round(PI * h * differenceSquare);

        string strH = MyGeneral::RoundStr(h);

        cout << "v = �� * h (r1^2 - r2^2)" << endl;
        cout << "v = " << PI << " * " << strH << " * (" << fixed << MyGeneral::RoundStr(r1) << "^2 - " << fixed << MyGeneral::RoundStr(r2) << "^2)" << endl;

        cout << "v = " << PI << " * " << strH << " * (" << fixed << MyGeneral::RoundStr(square1) << " - " << fixed << MyGeneral::RoundStr(square2) << ")" << endl;
        cout << "v = " << PI << " * " << fixed << strH << " * " << fixed << MyGeneral::RoundStr(differenceSquare) << endl;

        cout << "v = " << fixed << MyGeneral::RoundStr(result) << endl;
        return result;
    }


public:
    void Init() { //�������������� � ������������� (����-����� ����������)

        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, MyGeneral::White);

        cout << "\n��������� v (�����) ������ ��������\n";
        cout << "������� h\n";
        cout << "������� �������� r1\n";
        cout << "���������� �������� r2\n\n";

        cout << "�� �������: v = �� * h (r1^2 - r2^2)\n\n";


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

            h = myInput.InputData("������� ������ ��������: ", MIN, MAX);

            while (true) {
                SetConsoleTextAttribute(handle, MyGeneral::White);

                r1 = myInput.InputData("������� ������� ������ ��������: ", MIN, MAX);
                r2 = myInput.InputData("������� ���������� ������ ��������: ", MIN, MAX);

                if (r1 <= r2) {
                    SetConsoleTextAttribute(handle, MyGeneral::Red);
                    cout << endl << "������� ������ �������� ������ ���� ������ �����������!" << endl;
                }
                else
                    break;
            }

        }

        h = MyGeneral::Round(h);
        r1 = MyGeneral::Round(r1);
        r2 = MyGeneral::Round(r2);

        SetConsoleTextAttribute(handle, MyGeneral::Yellow);
        cout << endl << "���������� ������:" << endl;
        cout << "������ �������� (h): " << MyGeneral::RoundStr(h) << endl;
        cout << "������� ������ �������� (r1): " << MyGeneral::RoundStr(r1) << endl;
        cout << "���������� ������ �������� (r2): " << MyGeneral::RoundStr(r2) << endl << endl;


        SetConsoleTextAttribute(handle, MyGeneral::Green);
        printVolume(h, r1, r2);

        SetConsoleTextAttribute(handle, MyGeneral::White);

    }

};

