#ifndef LAB_1_LIST_H
#define LAB_1_LIST_H

#include "../sorts/sorts.h"

template<class T>
class List {
public:
    virtual void add(T obj, int index = -1) = 0;

    virtual void remove(int index) = 0;

    virtual T &get(int index) = 0;

    virtual int find(T obj) = 0;

    virtual void clear() = 0;

    virtual void sort(void (*sort_func)(T *, int) = nullptr) = 0;

    virtual void sort(void (*)(T *, int, int(*)(T &obj1, T &obj2)),
                      int(*)(T &obj1, T &obj2) = nullptr) = 0;

    virtual int get_size() = 0;
};

#endif //LAB_1_LIST_H
