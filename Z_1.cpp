#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void func4(float& x, float& dx, vector<float>& yValues) {
    float y = 0;
    while (x <= 10) {
        int a = 8, b = -2, r = 2;
        y = sqrt(pow(r, 2) - pow(x, 2) + (2 * a * x) - pow(a, 2)) + b;
        yValues.push_back(y);
        x += dx;
    }
}

void func3(float& x, float& dx, vector<float>& yValues) {
    float y = 0;
    while (x <= 6) {
        y = -2;
        yValues.push_back(y);
        x += dx;
    }
}

void func2(float& x, float& dx, vector<float>& yValues) {
    float y = 0;
    while (x <= 4) {
        y = x * (-0.5);
        yValues.push_back(y);
        x += dx;
    }
}

void func1(float& x, float& dx, vector<float>& yValues) {
    float y = 0;
    while (x <= -2) {
        y = x + 3;
        yValues.push_back(y);
        x += dx;
    }
}

void main_func(float& x, float& dx) {
    vector<vector<float>> allYValues; // Контейнер для хранения всех значений y

    // Вызов функций и сохранение значений y в контейнере
    {
        vector<float> yValues;
        func1(x, dx, yValues);
        allYValues.push_back(yValues);
    }
    x = -1.5;
    {
        vector<float> yValues;
        func2(x, dx, yValues);
        allYValues.push_back(yValues);
    }
    x = 4.5;
    {
        vector<float> yValues;
        func3(x, dx, yValues);
        allYValues.push_back(yValues);
    }
    x = 6.5;
    {
        vector<float> yValues;
        func4(x, dx, yValues);
        allYValues.push_back(yValues);
    }

    // Вывод значений y в одном столбце

    cout << "-4< x <-2" << "     " << "-2< x <4" << "        " << "4< x <6" << "        " << "6< x <10" << endl;
    cout << "___________________________________________________________" << endl;
    size_t maxSize = 0;
    for (const auto& yValues : allYValues) {
        maxSize = max(maxSize, yValues.size());
    }

    for (size_t i = 0; i < maxSize; ++i) {
        for (const auto& yValues : allYValues) {
            if (i < yValues.size()) {
                cout << " " << setprecision(2) << yValues[i] << "\t|\t";
            }
            else {
                cout << " \t|\t";
            }
        }
        cout << endl;
    }
}

int main() {
    float x = -4;
    float dx = 0.5;

    main_func(x, dx);

    return 0;
}

