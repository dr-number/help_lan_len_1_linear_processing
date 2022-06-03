#pragma once
#include <iostream>
#include <Windows.h>
#include <random>
#include <regex>

#define PI 3.14159265
using namespace std;

class MyGeneral
{

    public:
        static enum ConsoleColor
        {
            Blue = 1,
            Green = 2,
            Red = 4,
            Yellow = 14,
            White = 15
        };

        static string GetLine() {
            string line;
            getline(cin, line);
            cin.clear();
            return line;
        }

        //���������� ����� (������� ������)
        static string RoundStr(float var, int after = 2) {

            string s = to_string(var);
            int size = s.size();

            string result = "";
            bool isAfter = false;
            int afterCount = 0;

            for (int i = 0; i < size; ++i) {

                if (afterCount == after)
                    break;

                if (isAfter)
                    ++afterCount;

                if (!isAfter && s[i] == ',')
                    isAfter = true;

                result += s[i];

            }

            return result;
        }

        //���������� �����
        static float Round(float var)
        {
            // 37.66666 * 100 = 3766.66
            // 3766.66 + .5 = 3767.16 ��� �������� ����������

            // ����� ������ ��� int � �������� 3767
            // ����� ����� �� 100, ������� �������� ������������� � 37,67

            float value = (int)(var * 100 + .5);
            return stod(RoundStr((float)value / 100));

        }
};

