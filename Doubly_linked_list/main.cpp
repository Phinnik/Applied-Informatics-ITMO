//
// Created by Philipp on 24.09.2020.
//

#include "int_list_t.h"
#include "iostream"

using namespace std;


int main() {

    int_list_t test_list_a;
    int_list_t test_list_b{10, 0};
    int_list_t test_list_c{test_list_b};
    for (int i = 1; i < 6; ++i) {
        test_list_c.push_front(i);
        test_list_c.pop_back();
    }
    cout << "test_list_a: " << test_list_a;
    cout << "test_list_b: " << test_list_b;
    cout << "test_list_c: " << test_list_c;

    cout  << endl;

    int_list_t test_list_d;
    test_list_d = test_list_b;
    for (int i = 0; i < 10; ++i) {
        test_list_d.push_front(i);
        test_list_d.pop_back();
    }
    cout << "test_list_c: " << test_list_b;
    cout << "test_list_d: " << test_list_d;

    cout  << endl;

    int_list_t test_list_e{10, 10};
    test_list_e.clear();
    cout << "test_list_e: " << test_list_e;

    cout  << endl;
    cin >> test_list_e;
}