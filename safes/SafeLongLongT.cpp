//
// Created by Philipp on 18.09.2020.
//

#include "SafeLongLongT.h"
#include "iostream"

SafeLongLongT::SafeLongLongT(long long int v) {
    value = v;
}

void SafeLongLongT::setValue(long long v) {
    value = v;
}

long long SafeLongLongT::getValue() const {
    return value;
}


SafeLongLongT &SafeLongLongT::operator=(const SafeLongLongT &sllt) {
    if (this != &sllt) {
        value = sllt.value;
    }
    return *this;
}

SafeLongLongT SafeLongLongT::operator+(SafeLongLongT &sllt) const {
    return SafeLongLongT(value + sllt.value);
}

SafeLongLongT SafeLongLongT::operator-(SafeLongLongT &sllt) const {
    return SafeLongLongT(value - sllt.value);
}

SafeLongLongT SafeLongLongT::operator*(SafeLongLongT &sllt) const {
    return SafeLongLongT(value * sllt.value);
}

SafeLongLongT SafeLongLongT::operator/(SafeLongLongT &sllt) const {
    return SafeLongLongT(value / sllt.value);
}

bool SafeLongLongT::operator<(SafeLongLongT &sllt) const {
    return value < sllt.value;
}

bool SafeLongLongT::operator>(SafeLongLongT &sllt) const {
    return value > sllt.value;
}

bool SafeLongLongT::operator==(SafeLongLongT &sllt) const {
    return value == sllt.value;
}

std::ostream &operator<<(std::ostream &out, const SafeLongLongT &sllt) {
    out << sllt.value;
    return out;
}

std::istream &operator>>(std::istream &inp, SafeLongLongT &sllt) {
    inp >> sllt.value;
    return inp;
}
