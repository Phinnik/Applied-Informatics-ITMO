//
// Created by Philipp on 07.09.2020.
//

// TODO: проверка входных параметров
// TODO: добавление возможности вводить функцию вручную

#include <cmath>
#include <iostream>
#include <limits>
#include <string>


//
// получение значений функций
//
long double getFirstFuncValue(float n) {
    return -n * std::log(n);
}

long double getSecondFuncValue(float n) {
    return std::sqrt(n);
}

long double getThirdFuncValue(float n) {
    return -std::pow(n, 2) - 0.5;
}

//
// функции для получения минимальных и максимальных значений
//
long double getMinValue(const long double *values, int length) {
    long double minValue = std::numeric_limits<long double>::infinity();
    for (int i = 0; i < length; ++i) {
        if (values[i] < minValue) {
            minValue = values[i];
        }
    }
    return minValue;
}


int getMinValue(const int *values, int length) {
    int minValue = std::numeric_limits<int>::infinity();
    for (int i = 0; i < length; ++i) {
        if (values[i] < minValue) {
            minValue = values[i];
        }
    }
    return minValue;
}

long double getMaxValue(const long double *values, int length) {
    long double maxValue = -std::numeric_limits<long double>::infinity();
    for (int i = 0; i < length; ++i) {
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }
    return maxValue;
}

int getMaxValue(const int *values, int length) {
    int maxValue = -std::numeric_limits<int>::infinity();
    for (int i = 0; i < length; ++i) {
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }
    return maxValue;
}

int main() {

    // входные данные
    int plotWidth;
    int plotHeight;
    long double x0;
    long double x1;
    int funcNum;

    long double funcValues[200];
    long double xOffset;

    // ввод данных
    std::cout << "Enter function number: " << std::endl;
    std::cout << "\t1) -n * log(n)" << std::endl;
    std::cout << "\t2) sqrt(n)" << std::endl;
    std::cout << "\t3) -n^2 - 0.5" << std::endl;

    std::cin >> funcNum;
    std::cout << "Enter plot width (number of columns): ";
    std::cin >> plotWidth;
    std::cout << "Enter plot height (number of rows): ";
    std::cin >> plotHeight;
    std::cout << "Enter x0: ";
    std::cin >> x0;
    std::cout << "Enter x1: ";
    std::cin >> x1;

    std::cout << x1 << std::endl;

    xOffset = (x1 - x0) / (plotWidth - 1);

    // вычисление значений
    if (funcNum == 1) {
        for (int i = 0; i < plotWidth; ++i) {
            funcValues[i] = getFirstFuncValue(x0 + i * xOffset);
        }
    } else if (funcNum == 2) {
        for (int i = 0; i < plotWidth; ++i) {
            funcValues[i] = getSecondFuncValue(x0 + i * xOffset);
        }
    } else if (funcNum == 3) {
        for (int i = 0; i < plotWidth; ++i) {
            funcValues[i] = getThirdFuncValue(x0 + i * xOffset);
        }
    }

    long double maxValue = getMaxValue(funcValues, plotWidth);
    long double minValue = getMinValue(funcValues, plotWidth);

    // обязательная отрисовка нуля
    if (maxValue > 0 and minValue > 0) {
        minValue = 0;
    } else if (maxValue < 0 and minValue < 0) {
        maxValue = 0;
    }

    long double yTick = (maxValue - minValue) / plotHeight;

    int scaledValues[200];

    for (int i = 0; i < plotWidth; ++i) {
        scaledValues[i] = floor(funcValues[i] / yTick);
    }

    // отрисовка графика
    std::string line;
    for (int i = getMaxValue(scaledValues, plotWidth); i >= getMinValue(scaledValues, plotWidth); --i) {
        line = "";
        for (int j = 0; j < plotWidth; ++j) {
            if (i == 0) {
                line += "-";
            } else if ((i > 0 and scaledValues[j] > 0 and scaledValues[j] >= i) or
                       (i < 0 and scaledValues[j] < 0 and scaledValues[j] <= i)) {
                line += "#";
            } else {
                line += " ";
            }
        }
        std::cout << line << std::endl;
    }

    return 0;
}
