#ifndef LAB_1_SERIES_H
#define LAB_1_SERIES_H

#include <ostream>
#include "Character.h"
#include "../lists/ArrayList.h"

class Series {
    std::vector<Book> books;

public:
    void add_book(Book &book);

    void remove_book(Book &book);

    std::vector<Book> &getBooks();

    friend std::ostream &operator<<(std::ostream &os, Series &series);

    bool operator==(Series &rhs);

    bool operator!=(Series &rhs);

    bool operator<(Series &rhs);

    bool operator>(Series &rhs);

    bool operator<=(Series &rhs);

    bool operator>=(Series &rhs);
};

#endif //LAB_1_SERIES_H
