#pragma once
#include <Windows.h>
#include <iostream>
#include <regex>

#include "MyGeneral.h"

class MyRandom {

public:
    static const int MIN_RANDOM = 2, MAX_RANDOM = 1000;

    //���������� ����� �� ������������� �������� ������ �� ������ ��������� ������.
    bool isRandomData() {
        cout << "������������� ������ ��������� ������� [y/n]?" << endl;

        string answer = MyGeneral::GetLine();

        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        return answer == "y" || answer == "";
    }

    //��������� ���������� ����� � �������� ���������
    double GetRandom(int min, int max) {

        random_device random_device; // �������� ��������.
        mt19937 generator(random_device()); // ��������� ��������� �����.

        // (����� ������� ���� ���������������� ��������, ����� ����� ������)
        uniform_int_distribution<> distribution(min, max); // ����������� ������������� [min, max]

        return distribution(generator);
    }


};

