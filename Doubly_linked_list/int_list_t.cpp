//
// Created by Philipp on 24.09.2020.
//

#include "int_list_t.h"

#include "istream"
#include "iostream"

using namespace std;

int_list_t::int_list_t() {
    list_size = 0;
    head = nullptr;
    tail = nullptr;
}


int_list_t::int_list_t(const int_list_t &other) {
    list_size = other.list_size;
    head = nullptr;
    tail = nullptr;
    auto currentNode = other.head;
    while (currentNode != nullptr) {
        push_back(currentNode->data);
        currentNode = currentNode->pNext;
    }
}


int_list_t::int_list_t(size_t count, int value) {
    list_size = 0;
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < count; ++i) {
        push_back(value);
    }
}


int_list_t::~int_list_t() {
    clear();
    delete head;
    delete tail;
}


int_list_t &int_list_t::operator=(const int_list_t &other) {
    int_list_t copyIntList(other);
    swap(copyIntList);
    return *this;
}


int int_list_t::operator[](size_t pos) const {
    return this->getNode(pos)->data;
}


int &int_list_t::back() {
    return head->data;
}


int int_list_t::back() const {
    return head->data;
}


int &int_list_t::front() {
    return tail->data;
}


int int_list_t::front() const {
    return tail->data;
}


void int_list_t::clear() {
    while (list_size != 0) {
        pop_front();
    }
}


size_t int_list_t::size() const {
    return list_size;
}


bool int_list_t::empty() const {
    return list_size != 0;
}


// if "index out of range" it does push_back or push_front
void int_list_t::insert(size_t pos, int new_val) {
    if (pos <= 0) {
        push_back(new_val);
    } else if (pos >= list_size) {
        push_front(new_val);
    } else {
        node_t *nextNode = this->getNode(pos);
        auto *newNode = new node_t{nextNode->pPrev, nextNode, new_val};
        nextNode->pPrev->pNext = newNode;
        nextNode->pPrev = newNode;
        list_size++;
    }
}


void int_list_t::push_front(int new_val) {
    if (tail == nullptr) {
        tail = new node_t{nullptr, nullptr, new_val};
        head = tail;
    } else {
        auto *tempNode = new node_t{tail, nullptr, new_val};
        tail->pNext = tempNode;
        tail = tempNode;
    }
    list_size++;
}


void int_list_t::push_back(int new_val) {
    if (head == nullptr) {
        head = new node_t{nullptr, nullptr, new_val};
        tail = head;

    } else {
        auto *tempNode = new node_t{nullptr, head, new_val};
        head->pPrev = tempNode;
        head = tempNode;
    }
    list_size++;
}


// if "index out of range" it does pop_back or pop_front
void int_list_t::erase(size_t pos) {
    if (pos <= 0) {
        pop_back();
    } else if (pos >= list_size) {
        pop_front();
    } else {
        node_t *currentNode = getNode(pos);
        currentNode->pPrev->pNext = currentNode->pNext;
        currentNode->pNext->pPrev = currentNode->pPrev;
        delete currentNode;
    }
    list_size--;
}


// TODO: handle single item can be simplified (maybe)
void int_list_t::pop_front() {
    if (list_size == 1) {
        node_t *currentNode = this->tail;
        delete currentNode;
        this->tail = nullptr;
        this->head = nullptr;
        list_size = 0;
    } else if (list_size > 1) {
        node_t *currentNode = this->tail;
        currentNode->pPrev->pNext = nullptr;
        this->tail = currentNode->pPrev;
        delete currentNode;
        list_size--;
    }
}


// TODO: handle single item can be simplified (maybe)
void int_list_t::pop_back() {
    if (list_size == 1) {
        node_t *currentNode = this->head;
        delete currentNode;
        this->tail = nullptr;
        this->head = nullptr;
        list_size = 0;
    } else if (list_size > 1) {
        node_t *currentNode = this->head;
        currentNode->pNext->pPrev = nullptr;
        this->head = currentNode->pNext;
        delete currentNode;
        list_size--;
    }
}


int_list_t int_list_t::splice(size_t start_pos, size_t count) {
    int_list_t new_int_list_t;
    new_int_list_t.list_size = count;
    new_int_list_t.head = nullptr;
    new_int_list_t.tail = nullptr;
    node_t *currentNode = getNode(start_pos);
    for (int i = 0; i < count; ++i) {
        new_int_list_t.push_back(currentNode->data);
    }
    return new_int_list_t;
}


int_list_t &int_list_t::merge(int_list_t &other) {
    node_t *currentNode = other.head;
    for (int i = 0; i < other.list_size; ++i) {
        push_front(currentNode->data);
        currentNode = currentNode->pNext;
    }
    other.clear();
    return *this;
}


void int_list_t::reverse() {
    for (auto currentNode = head; currentNode != nullptr; currentNode = currentNode->pPrev) {
        std::swap(currentNode->pPrev, currentNode->pNext);
    }
    std::swap(head, tail);
}


void int_list_t::swap(int_list_t &other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(list_size, other.list_size);
}


std::istream &operator>>(istream &stream, int_list_t &list) {
    list.clear();
    int size;
    cout << "enter size:" << endl;
    stream >> size;
    int value = 0;
    for (int i = 0; i < size; ++i) {
        cout << "type " << i + 1 << " value:" << endl;
        stream >> value;
        list.push_front(value);
    }
    return stream;
}


// TODO: it can be simplified (maybe)
std::ostream &operator<<(std::ostream &stream, const int_list_t &list) {
    if (list.list_size == 0) {
        stream << "[ ]" << endl;
    } else if (list.list_size == 1) {
        stream << "[ " << list.head->data << " ]" << endl;
    } else {
        auto currentNode = list.head;
        stream << "[ ";
        while (currentNode->pNext != nullptr) {
            stream << currentNode->data << " ";
            currentNode = currentNode->pNext;
        }
        stream << currentNode->data << " ";
        stream << "]" << endl;
    }

    return stream;
}


// TODO: kind of shitcode. Refactor!
int_list_t::node_t *int_list_t::getNode(size_t pos) const {
    if (pos > list_size / 2) {
        auto currentNode = tail;
        for (int i = 0; i < list_size - pos - 1; ++i) {
            currentNode = currentNode->pPrev;
        }
        return currentNode;
    } else {
        auto currentNode = head;
        for (int i = 0; i < pos; ++i) {
            currentNode = currentNode->pNext;
        }
        return currentNode;
    }
}
