#ifndef LAB_1_VECTORLIST_H
#define LAB_1_VECTORLIST_H

#include "List.h"
#include <vector>
#include <iostream>

template<class T>
class VectorList : List<T> {
    std::vector<T> vect;

public:
    ~VectorList() {
        clear();
    }

    void add(T obj, int index = -1) override {
        if (index < 0)
            index = vect.size();
        else if (index > vect.size())
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");

        if (index == vect.size()) vect.push_back(obj);
        else vect.insert(vect.begin() + index, obj);
    }

    void remove(int index) override {
        if ((index >= 0 && index >= vect.size()) || (index < 0 && vect.size() == 0))
            throw std::out_of_range(
                    "index " + std::to_string(index) + " is greater then the size-1 :" + std::to_string(vect.size()));
        else if (index < 0)
            index = vect.size() - 1;

        vect.erase(vect.begin() + index);
    }

    T &get(int index) override {
        if ((index >= 0 && index >= vect.size()) || (index < 0 && vect.size() == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = vect.size() - 1;

        return vect.at(index);
    }

    int find(T obj) override {
        int res = -1;

        for (int i = 0; i < vect.size(); i++) {
            if (vect[i] == obj) {
                res = i;
                break;
            }
        }
        return res;
    }

    void clear() override {
        vect.clear();
    }

    void sort(void (*sort_func)(T *, int)) {
        if (!sort_func)
            quick_sort(&vect[0], vect.size());
        else
            sort_func(&vect[0], vect.size());
    }

    void sort(void (*sort_func)(T *, int, int (*)(T &, T &)), int (*compare_func)(T &, T &) = nullptr) override {
        sort_func(&vect[0], vect.size(), compare_func);
    }

    static void sort(std::vector<T> global_vector, void (*sort_func)(T *, int, int (*)(T &, T &)),
                     int (*compare_func)(T &, T &) = nullptr) {
        sort_func(&global_vector[0], global_vector.size(), compare_func);
    }

    int get_size() override {
        return vect.size();
    }

    friend std::ostream &operator<<(std::ostream &out, VectorList<T> &list) {
        out << '[';
        if (list.vect.size() != 0) {
            for (int i = 0; i < list.get_size() - 1; i++) {
                out << list.get(i) << ", ";
            }
            out << list.get(list.get_size() - 1);
        }
        out << ']';
    }

    bool operator==(VectorList &rhs) {
        if (get_size() != rhs.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != rhs.get(i)) return false;
        }
        return true;
    }

    bool operator!=(VectorList &rhs) {
        return !(rhs == *this);
    }

    bool operator<(VectorList &rhs) {
        if (get_size() < rhs.get_size()) return true;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) < rhs.get(i)) return true;
        }
        return false;
    }

    bool operator>(VectorList &rhs) {
        return rhs < *this;
    }

    bool operator<=(VectorList &rhs) {
        return !(rhs < *this);
    }

    bool operator>=(VectorList &rhs) {
        return !(*this < rhs);
    }

};


#endif //LAB_1_VECTORLIST_H
