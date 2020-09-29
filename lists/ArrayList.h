#ifndef LAB_1_ARRAYLIST_H
#define LAB_1_ARRAYLIST_H

#include <iostream>
#include "List.h"

template<class T>
class ArrayList : List<T> {
private:
    int size = 0;
    int arr_size = 2;
    T *arr = new T[16];

    void change_arr_size(int new_size) {
        if (new_size <= size) new_size *= 2;

        T *temp = new T[new_size];
        for (int i = 0; i < arr_size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        arr_size = new_size;
    }

public:
    ~ArrayList() {
        delete[] arr;
    }

    void add(T obj, int index = -1) override {
        if (index < 0)
            index = size;
        else if (index > size)
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");

        if (size == arr_size)
            change_arr_size(arr_size / 2 * 3 + 2);

        T temp1 = obj;
        T temp2;
        while (index <= size) {
            temp2 = arr[index];
            arr[index] = temp1;
            std::swap(temp1, temp2);
            index++;
        }
        size++;
    }

    void remove(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = size - 1;

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    T &get(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = size - 1;

        return arr[index];
    }

    int find(T obj) override {
        int res = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == obj) {
                res = i;
                break;
            }
        }
        return res;
    }

    void clear() override {
        delete[] arr;
        size = 0;
        arr_size = 16;
        arr = new T[arr_size];
    }

    void sort(void (*sort_func)(T *, int) = nullptr) {
        if (!sort_func)
            quick_sort(arr, size);
        else
            sort_func(arr, size);
    }

    void sort(void (*sort_func)(T *, int, int(*)(T &obj1, T &obj2)),
              int(*compare_func)(T &obj1, T &obj2) = nullptr) override {
        sort_func(arr, size, compare_func);
    }

    static void sort(T *global_arr, int global_size, void (*sort_func)(T *, int, int(*)(T &obj1, T &obj2)),
                     int(*compare_func)(T &obj1, T &obj2) = nullptr) {
        sort_func(global_arr, global_size, compare_func);
    }

    int get_size() override {
        return size;
    }

    friend std::ostream &operator<<(std::ostream &out, const ArrayList<T> &list) {
        out << '[';
        for (int i = 0; i < list.size - 1; i++) {
            out << list.arr[i] << ", ";
        }
        if (list.size != 0)
            out << list.arr[list.size - 1];

        out << "]";
    }

    bool operator==(ArrayList &rhs) {
        if (get_size() != rhs.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != rhs.get(i)) return false;
        }
        return true;
    }

    bool operator!=(ArrayList &rhs) {
        return !(rhs == *this);
    }

    bool operator<(ArrayList &rhs) {
        if (get_size() < rhs.get_size()) return true;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) < rhs.get(i)) return true;
        }
        return false;
    }

    bool operator>(ArrayList &rhs) {
        return rhs < *this;
    }

    bool operator<=(ArrayList &rhs) {
        return !(rhs < *this);
    }

    bool operator>=(ArrayList &rhs) {
        return !(*this < rhs);
    }
};
#endif //LAB_1_ARRAYLIST_H
