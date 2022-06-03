#pragma once
#include <Windows.h>
#include <iostream>
#include <regex>

#include "MyGeneral.h"

class MyRandom {

public:
    static const int MIN_RANDOM = 2, MAX_RANDOM = 1000;

    //определ€ет нужно ли сгенерировать исходные данные на основе случайных данных.
    bool isRandomData() {
        cout << "—генерировать данные случайным образом [y/n]?" << endl;

        string answer = MyGeneral::GetLine();

        transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

        return answer == "y" || answer == "";
    }

    //генераци€ случайного числа в заданном интервале
    double GetRandom(int min, int max) {

        random_device random_device; // »сточник энтропии.
        mt19937 generator(random_device()); // √енератор случайных чисел.

        // («десь беретс€ одно инициализирующее значение, можно брать больше)
        uniform_int_distribution<> distribution(min, max); // –авномерное распределение [min, max]

        return distribution(generator);
    }


};

