#ifndef LAB_1_COMPARE_H
#define LAB_1_COMPARE_H
#include "../lab_classes/Book.h"

int compare_int_reverse(int &, int &);

int compare_double_reverse(double &, double &);

int compare_string_reverse(std::string &, std::string &);

int compare_vector_reverse(std::vector<int> &, std::vector<int> &);

int compare_book_by_name(Book &, Book &);

int compare_book_by_date(Book &, Book &);

#endif //LAB_1_COMPARE_H
