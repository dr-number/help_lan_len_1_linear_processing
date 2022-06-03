#pragma once
#include "MyRandom.h"
#include "MyGeneral.h"
#include "MyInput.h"

class Task16 {

private:
    const int MIN = MyRandom::MIN_RANDOM;
    const int MAX = MyRandom::MAX_RANDOM;

    double degreeToRadian(double degree) {
        return (degree * PI) / 180;
    }

    double radianToDegree(double radian) {
        return (radian * 180) / PI;
    }

    //��������� ������� ��������������� �� ������� � ������
    double printSquare(double side, double height) {

        cout << "S = a * h" << endl;
        cout << "S = " << MyGeneral::RoundStr(side) << " * " << MyGeneral::RoundStr(height) << endl;

        double result = MyGeneral::Round(side * height);
        cout << "S = " << MyGeneral::RoundStr(result) << endl;

        return result;
    }

    //�������� �������� ������ ���� �� ������������,
    //���� �� ������ ��������� ������ � ��������� ������� ��������������� � ������� ������� printSquare(side, height)
    double printSquareCorner(double side1, double side2, double corner) {

        string strSide1 = MyGeneral::RoundStr(side1);
        string strSide2 = MyGeneral::RoundStr(side2);

        cout << "S = a * b * sin(A)" << endl;
        cout << "S = " << fixed << strSide1 << " * " << fixed << strSide2 << " * sin(" << fixed << MyGeneral::RoundStr(corner) << ")" << endl;

        double sinCorner = sin(degreeToRadian(corner));

        cout << "S = " << fixed << strSide1 << " * " << fixed << strSide2 << " * " << fixed << MyGeneral::RoundStr(sinCorner) << endl;

        double result = MyGeneral::Round(side1 * side2 * sinCorner);

        cout << "S = " << fixed << MyGeneral::RoundStr(result) << endl;

        return result;
    }

    //��������� ������� ��������������� �� �������� � ���� ����� ����
    double printSquareDiagonals(double d1, double d2, double corner) {

        double sinCorner = sin(degreeToRadian(corner));
        double result = MyGeneral::Round((d1 * d2 * sinCorner) / 2);

        string strD1 = MyGeneral::RoundStr(d1);
        string strD2 = MyGeneral::RoundStr(d2);

        cout << "S = 0.5 * d1 * d2 * sin(A)" << endl;
        cout << "S = 0.5 * " << fixed << strD1 << " * " << fixed << strD2 << " * sin(" << fixed << MyGeneral::RoundStr(corner) << ")" << endl;

        cout << "S = 0.5 * " << fixed << strD1 << " * " << fixed << strD2 << " * " << fixed << MyGeneral::RoundStr(sinCorner) << endl;
        cout << "S = " << fixed << MyGeneral::RoundStr(result) << endl;

        return result;
    }

public:
    //�������� �������� ������ ���� �� ������������,
    //���� �� ������ ��������� ������ � ��������� ������� ��������������� � ������� ������� printSquareCorner(side1, side2, corner)
    void InitSideHeight() {
        HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        double side, height;

        MyRandom myRandom = *new MyRandom();

        if (myRandom.isRandomData()) {
            side = myRandom.GetRandom(MIN, MAX);
            height = myRandom.GetRandom(MIN, MAX);
        }
        else {
            MyInput myInput = *new MyInput();
            side = myInput.InputData("������� ������� ���������������: ", MIN, MAX);
            height = myInput.InputData("������� ������ ���������������: ", MIN, MAX);
        }

        side = MyGeneral::Round(side);
        height = MyGeneral::Round(height);

        SetConsoleTextAttribute(handleConsole, MyGeneral::Yellow);
        cout << endl << "���������� ������:" << endl;
        cout << "������� ��������������� (a): " << MyGeneral::RoundStr(side) << endl;
        cout << "������ ���������������: (h): " << MyGeneral::RoundStr(height) << endl << endl;

        SetConsoleTextAttribute(handleConsole, MyGeneral::Green);
        printSquare(side, height);

        SetConsoleTextAttribute(handleConsole, MyGeneral::White);
    }

    void InitSidesCorner() {
        HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        double side1, side2, corner;

        MyRandom myRandom = *new MyRandom();

        if (myRandom.isRandomData()) {
            side1 = myRandom.GetRandom(MIN, MAX);
            side2 = myRandom.GetRandom(MIN, MAX);
            corner = myRandom.GetRandom(MIN, 89);
        }
        else {
            MyInput myInput = *new MyInput();
            side1 = myInput.InputData("������� ������ ������� ��������������� (�): ", MIN, MAX);
            side2 = myInput.InputData("������� ������ ������� ��������������� (b): ", MIN, MAX);
            corner = myInput.InputData("������� ���� ����� ��������� � � b (A) [� ��������]: ", MIN, 90);
        }

        side1 = MyGeneral::Round(side1);
        side2 = MyGeneral::Round(side2);
        corner = MyGeneral::Round(corner);

        SetConsoleTextAttribute(handleConsole, MyGeneral::Yellow);
        cout << endl << "���������� ������:" << endl;
        cout << "������ ������� ��������������� (�): " << MyGeneral::RoundStr(side1) << endl;
        cout << "������ ������� ��������������� (b): " << MyGeneral::RoundStr(side2) << endl;
        cout << "���� ����� ��������� � � b (A) [� ��������]: " << MyGeneral::RoundStr(corner) << endl << endl;

        SetConsoleTextAttribute(handleConsole, MyGeneral::Green);
        printSquareCorner(side1, side2, corner);

        SetConsoleTextAttribute(handleConsole, MyGeneral::White);
    }

    //��������� ������� ��������������� �� ���������� � ���� ����� ����.
    void InitSidesDiagonals() {
        HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        double d1, d2, corner;

        MyRandom myRandom = *new MyRandom();

        if (myRandom.isRandomData()) {
            d1 = myRandom.GetRandom(MIN, MAX);
            d2 = myRandom.GetRandom(MIN, MAX);
            corner = myRandom.GetRandom(MIN, 179);
        }
        else {
            MyInput myInput = *new MyInput();
            d1 = myInput.InputData("������� ������ ��������� ��������������� (d1): ", MIN, MAX);
            d2 = myInput.InputData("������� ������ �������� ��������������� (d2): ", MIN, MAX);
            corner = myInput.InputData("������� ���� ����� ����������� d1 � d2 (A): ", MIN, 180);
        }

        d1 = MyGeneral::Round(d1);
        d2 = MyGeneral::Round(d2);
        corner = MyGeneral::Round(corner);

        SetConsoleTextAttribute(handleConsole, MyGeneral::Yellow);
        cout << endl << "���������� ������:" << endl;
        cout << "������ ��������� ��������������� (d1): " << MyGeneral::RoundStr(d1) << endl;
        cout << "������ ��������� ��������������� (d2): " << MyGeneral::RoundStr(d2) << endl;
        cout << "���� ����� ����������� d1 � d2 (A): " << MyGeneral::RoundStr(corner) << endl << endl;

        SetConsoleTextAttribute(handleConsole, MyGeneral::Green);
        printSquareDiagonals(d1, d2, corner);

        SetConsoleTextAttribute(handleConsole, MyGeneral::White);
    }

    void Init() {
        HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handleConsole, MyGeneral::White);

        bool isGo = true;
        string select;

        while (isGo)
        {
            cout << "\n��������� S (�������) ���������������" << endl;
            cout << "�� ����� ������� ��������� ����������:" << endl << endl;

            cout << "1) �� ������� � ������" << endl;
            cout << "2) �� �������� � ���� ����� ����" << endl;
            cout << "3) �� ���������� � ���� ����� ����" << endl << endl;

            select = MyGeneral::GetLine();

            if (select == "1") {
                InitSideHeight();
                isGo = false;
            }
            else if (select == "2") {
                InitSidesCorner();
                isGo = false;
            }
            else if (select == "3") {
                InitSidesDiagonals();
                isGo = false;
            }
            else {
                SetConsoleTextAttribute(handleConsole, MyGeneral::Red);
                cout << "\n������������ ������!" << endl;
                SetConsoleTextAttribute(handleConsole, MyGeneral::White);
            }
        }
    }
};

