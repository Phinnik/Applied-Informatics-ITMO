//
// Created by Philipp on 18.09.2020.
//


#include "iostream"
#include "SafeLongLongT.h"
#include "SafeCArrayT.h"
#include "array"

using namespace std;

void SafeLongLongTTest() {
    // constructor
    SafeLongLongT a{1};
    SafeLongLongT b{2};
    SafeLongLongT c{3};

    // operator=
    c = a;

    // operator>>
    cout << "enter c:" << endl;
    cin >> c;

    // operator<<
    cout << "c = " << c << endl;

    // arithmetic
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

}

void SafeCArrayTTest() {
    SafeCArrayT<int, 10> test_array;
    for (int i = 0; i < 10; ++i) {
        test_array[i] = i;
        cout << test_array[i] << endl;
    }
    SafeCArrayT<int, 10> another_array;
    another_array = test_array;
    another_array[1] = 20;
    cout << "another_array[1]=" << another_array[1] << "; test_array[1]=" << test_array[1] << endl;

    cout << "another_array[2]=" << another_array[2] << "; test_array[2]=" << test_array[2];
}

int main() {
    SafeLongLongTTest();
    cout << endl << endl;
    SafeCArrayTTest();
    return 0;
}