#include "Series.h"
#include "../lists/VectorList.h"
#include "../sorts/sorts.h"
#include "../compare_functions/compare.h"


void Series::add_book(Book &book) {
    books.push_back(book);
}

void Series::remove_book(Book &book) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i] == book) return;
    }
    books.push_back(book);
}


std::vector<Book> &Series::getBooks() {
    VectorList<Book>::sort(books, quick_sort, compare_book_by_date);
    return books;
}

std::ostream &operator<<(std::ostream &os, Series &series) {
    VectorList<Book>::sort(series.getBooks(), quick_sort);
    os << '{';
    if(!series.getBooks().empty()){
        for(int i = 0; i < series.getBooks().size() - 1; i++){
            os << series.getBooks()[i] << ", ";
        }
        os << series.getBooks().at(series.getBooks().size() - 1);
    }
    os << '}';

    return os;
}

bool Series::operator==(Series &rhs) {
    return books == rhs.getBooks();
}

bool Series::operator!=(Series &rhs) {
    return !(rhs == *this);
}

bool Series::operator<(Series &rhs){
    return books < rhs.books;
}

bool Series::operator>(Series &rhs) {
    return rhs < *this;
}

bool Series::operator<=(Series &rhs){
    return !(rhs < *this);
}

bool Series::operator>=(Series &rhs) {
    return !(*this < rhs);
}


