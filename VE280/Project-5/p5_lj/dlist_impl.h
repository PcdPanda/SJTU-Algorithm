#ifndef __DLIST_IMPL__
#define __DLIST_IMPL__

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;

template<class T>
bool Dlist<T>::isEmpty() const {
    return !first;
}

template<class T>
void Dlist<T>::insertFront(T *op) {
    node *front = new node;
    front->prev = NULL;
    front->next = NULL;
    front->op = op;

    if (isEmpty()) {
        first = last = front;
    } else {
        first->prev = front;
        front->next = first;
        first = front;
    }
}

template<class T>
void Dlist<T>::insertBack(T *op) {
    node *back = new node;
    back->prev = NULL;
    back->next = NULL;
    back->op = op;

    if (isEmpty()) {
        first = last = back;
    } else {
        last->next = back;
        back->prev = last;
        last = back;
    }
}


template<class T>
T *Dlist<T>::removeFront() {
    if (isEmpty()) {
        emptyList e;
        throw e;
    }

    node *toRemove = first;
    T *result = NULL;
    first = toRemove->next;
    if (first) {
        first->prev = NULL;
    } else {
        last = NULL;
    }
    result = toRemove->op;
    delete toRemove;
    return result;
}

template<class T>
T *Dlist<T>::removeBack() {
    if (isEmpty()) {
        emptyList e;
        throw e;
    }
    node *toRemove = last;
    T *result = NULL;
    last = toRemove->prev;
    if (last) {
        last->next = NULL;
    } else {
        first = NULL;
    }
    result = toRemove->op;
    delete toRemove;
    return result;
}

template<class T>
Dlist<T>::Dlist():first(0), last(0) {
}

template<class T>
Dlist<T>::Dlist(const Dlist &l)
        :first(0), last(0) {
    copyAll(l);
}

template<class T>
Dlist<T> &Dlist<T>::operator=(const Dlist<T> &l) {
    if (this != &l) {
        removeAll();
        copyAll(l);
    }
    return *this;
}

template<class T>
Dlist<T>::~Dlist() {
    removeAll();
}

template<class T>
void Dlist<T>::removeAll() {
    while (!isEmpty()) {
        T *op = removeFront();
        delete op;
    }
}

template<class T>
void Dlist<T>::copyAll(const Dlist<T> &l) {
    node *curNode = l.first;

    while (curNode) {
        insertBack((curNode->op));
        curNode = curNode->next;
    }
}

#endif // __DLIST_IMPL__

