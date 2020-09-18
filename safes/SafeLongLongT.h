//
// Created by Philipp on 18.09.2020.
//

#ifndef SAFES_SAFELONGLONGT_H
#define SAFES_SAFELONGLONGT_H

#include "iostream"

class SafeLongLongT {
public:
    explicit SafeLongLongT(long long v);

    SafeLongLongT &operator=(const SafeLongLongT &sllt);

    SafeLongLongT operator+(SafeLongLongT &sllt) const;

    SafeLongLongT operator-(SafeLongLongT &sllt) const;

    SafeLongLongT operator*(SafeLongLongT &sllt) const;

    SafeLongLongT operator/(SafeLongLongT &sllt) const;

    bool operator<(SafeLongLongT &sllt) const;

    bool operator>(SafeLongLongT &sllt) const;

    bool operator==(SafeLongLongT &sllt) const;

    friend std::ostream &operator<<(std::ostream &out, const SafeLongLongT &sllt);

    friend std::istream &operator>>(std::istream &inp, SafeLongLongT &sllt);

    void setValue(long long v);

    long long getValue() const;

private:
    long long value;
};


#endif //SAFES_SAFELONGLONGT_H
