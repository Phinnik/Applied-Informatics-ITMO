//
// Created by Philipp on 18.09.2020.
//


#include "iostream"
#include "SafeLongLongT.h"

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
    cout << "c = " << c<< endl;

    // arithmetic
    cout << a << " + " << b << " = " << a + b <<  endl;
    cout << a << " - " << b << " = " << a - b <<  endl;
    cout << a << " * " << b << " = " << a * b <<  endl;
    cout << a << " / " << b << " = " << a / b <<  endl;

}


int main() {
    SafeLongLongTTest();
}