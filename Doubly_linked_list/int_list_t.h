//
// Created by Philipp on 24.09.2020.
//

#ifndef APPLIED_INFORMATICS_ITMO_DOUBLYLINKEDLIST_H
#define APPLIED_INFORMATICS_ITMO_DOUBLYLINKEDLIST_H

#include <cstddef>
#include "istream"

class int_list_t {
private:
    struct node_t {
        node_t *pPrev;
        node_t *pNext;
        int data;
    };

    size_t list_size;
    node_t *head;
    node_t *tail;
    node_t *getNode(size_t pos) const;


public:
    int_list_t(); // O(1)
    int_list_t(const int_list_t &other); // COPY $other list O(other.size)
    int_list_t(size_t count, int value); // create list $count size and fill it with $value O($count)
    ~int_list_t();    // O(size)

    int_list_t &operator=(const int_list_t &other); // O(size + other.size())

    int operator[](size_t pos) const; // O(min($pos, size - $pos))

    int &back();    // last element O(1)
    int back() const; // O(1)

    int &front();    // first element O(1)
    int front() const; // O(1)

    void clear(); // O(size)
    size_t size() const; // O(1)
    bool empty() const; // O(1)

    void insert(size_t pos, int new_val); // insert element $new_val BEFORE element with index $pos O(min($pos, size - $pos))
    void push_front(int new_val); // O(1)
    void push_back(int new_val);    // O(1)

    void erase(size_t pos); // remove element with index $pos O(min($pos, size - $pos))
    void pop_front(); // O(1)
    void pop_back();  // O(1)

    int_list_t splice(size_t start_pos, size_t count); // splice part of list into result (not copy!) O($start_pos + $count)
    int_list_t &merge(int_list_t &other); // merge two lists, after operation $other must be valid empty list O(1)

    void reverse(); // O(size)
    void swap(int_list_t &other); // O(1)

    friend std::istream &operator>>(std::istream &stream, int_list_t &list);    // O(size)
    friend std::ostream &operator<<(std::ostream &stream, const int_list_t &list); // O(size)


};


#endif //APPLIED_INFORMATICS_ITMO_DOUBLYLINKEDLIST_H
