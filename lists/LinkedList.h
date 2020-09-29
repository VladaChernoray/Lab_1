#ifndef LAB_1_LINKEDLIST_H
#define LAB_1_LINKEDLIST_H

#include "List.h"

template<class T>
class LinkedList : List<T> {
private:
    class Node {
    public:
        T obj;
        Node *next = nullptr;

        Node(T &obj) {
            this->obj = obj;
        }

    };

    int size = 0;
    Node *head = nullptr;
    Node *ass = nullptr;

public:
//    ~LinkedList() {
//        if (size > 0) {
//            ass = head->next;
//            for (int i = 0; i < size - 1; i++) {
//                delete head;
//                head = ass;
//                ass = ass->next;
//            }
//            delete head;
//            delete ass;
//        }
//    }

    void add(T obj, int index = -1) override {
        if (index < 0)
            index = size;
        else if (index > size)
            throw std::out_of_range("your index " + std::to_string(index) + " is greater then the size");

        if (index == 0) {
            if (size == 0) {
                head = new Node(obj);
                ass = head;
            } else {
                Node *n = new Node(obj);
                n->next = head;
                head = n;
            }
        } else if (index < size) {
            Node *temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            Node *new_node = new Node(obj);
            new_node->next = temp->next;
            temp->next = new_node;
        } else if (index == size) {
            ass->next = new Node(obj);
            ass = ass->next;
        }
        size++;
    }

    void remove(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");
        else if (index < 0)
            index = size - 1;

        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
        } else {
            Node *temp = head;
            while (index != 1) {
                temp = temp->next;
                index--;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }

    T &get(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");
        else if (index < 0)
            index = size - 1;

        if (index == 0) {
            return head->obj;
        } else {
            Node *temp = head;
            while (index != 0) {
                temp = temp->next;
                index--;
            }
            return temp->obj;
        }
    }

    int find(T obj) override {
        int res = -1;

        Node *temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->obj == obj) {
                res = i;
                break;
            }
            temp = temp->next;
        }
        return res;
    }

    void clear() override {
        Node *temp = head;
        for (int i = 0; i < size; i++) {
            if (head->next != nullptr) temp = head->next;
            delete head;
            head = temp;
        }
        head = nullptr;
        size = 0;
    }

    void sort(void (*sort_func)(T *, int) = nullptr) {
        T *arr = new T[size];

        ass = head;
        for (int i = 0; i < size; i++) {
            arr[i] = ass->obj;
            ass = ass->next;
        }

        if (!sort_func)
            quick_sort(arr, size);
        else
            sort_func(arr, size);

        ass = head;
        for (int i = 0; i < size; i++) {
            ass->obj = arr[i];
            ass = ass->next;
        }
    }

    void sort(void (*sort_func)(T *, int, int(*)(T &obj1, T &obj2)),
              int(*compare_func)(T &obj1, T &obj2) = nullptr) override {
        T *arr = new T[size];

        ass = head;
        for (int i = 0; i < size; i++) {
            arr[i] = ass->obj;
            ass = ass->next;
        }

        sort_func(arr, size, compare_func);

        ass = head;
        for (int i = 0; i < size; i++) {
            ass->obj = arr[i];
            ass = ass->next;
        }
    }

    int get_size() override {
        return size;
    }

    friend std::ostream &operator<<(std::ostream &out, LinkedList<T> &list) {
        out << '[';
        list.ass = list.head;
        for (int i = 0; i < list.size - 1; i++) {
            out << list.ass->obj << ", ";
            list.ass = list.ass->next;
        }
        if (list.size != 0)
            out << list.ass->obj;
        out << ']';
    }

    bool operator==(LinkedList &rhs) {
        if (get_size() != rhs.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != rhs.get(i)) return false;
        }
        return true;
    }

    bool operator!=(LinkedList &rhs) {
        return !(rhs == *this);
    }

    bool operator<(LinkedList &rhs) {
        if (get_size() < rhs.get_size()) return true;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) < rhs.get(i)) return true;
        }
        return false;
    }

    bool operator>(LinkedList &rhs) {
        return rhs < *this;
    }

    bool operator<=(LinkedList &rhs) {
        return !(rhs < *this);
    }

    bool operator>=(LinkedList &rhs) {
        return !(*this < rhs);
    }
};

#endif //LAB_1_LINKEDLIST_H
