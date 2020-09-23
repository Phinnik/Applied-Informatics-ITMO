//
// Created by Philipp on 23.09.2020.
//

#ifndef SAFES_SAFECARRAYT_H
#define SAFES_SAFECARRAYT_H

#include "iostream"

template<typename T, int N>
class SafeCArrayT {
private:
    T *values;
    int length;
public:
    SafeCArrayT();

    ~SafeCArrayT();

    SafeCArrayT &operator=(const SafeCArrayT &other);

    T &operator[](int i);
};

template<typename T, int N>
SafeCArrayT<T, N>::SafeCArrayT() {
    values = new T[N];
    length = N;
}

template<typename T, int N>
SafeCArrayT<T, N>::~SafeCArrayT() {
    delete[] values;
}

template<typename T, int N>
SafeCArrayT<T, N> &SafeCArrayT<T, N>::operator=(const SafeCArrayT &other) {
    delete[] this->values;
    values = new T[N];
    for (int i = 0; i < other.length; ++i) {
        values[i] = other.values[i];
    }
    return *this;
}

template<typename T, int N>
T &SafeCArrayT<T, N>::operator[](const int i) {
    return this->values[i];
}


#endif //SAFES_SAFECARRAYT_H
