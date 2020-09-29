#include "Book.h"

#include <utility>

Book::Book() {
    Book::name = "noname";
    Book::pages = 0;
    Book::annotation = "";
    Book::date = "0000.00.00";
    Book::authors = new std::vector<std::string>;
}

Book::Book(std::string name,
           int pages,
           std::string annotation,
           std::string date,
           std::vector<std::string> *authors) :
        name(std::move(name)),
        pages(pages),
        annotation(std::move(annotation)),
        date(std::move(date)),
        authors(authors) {}

Book::Book(std::string name,
           int pages,
           std::string annotation,
           std::string date,
           const std::string& author1,
           const std::string& author2,
           const std::string& author3)  :
        name(std::move(name)),
        pages(pages),
        annotation(std::move(annotation)),
        date(std::move(date)) {
    Book::authors = new std::vector<std::string>;
    Book::authors->push_back(author1);
    if(!author2.empty())
        Book::authors->push_back(author2);
    if(!author3.empty())
        Book::authors->push_back(author3);
}

const std::string &Book::getName() const {
    return name;
}

void Book::setName(const std::string &name) {
    Book::name = name;
}

int Book::getPages() const {
    return pages;
}

void Book::setPages(int pages) {
    Book::pages = pages;
}

const std::string &Book::getAnnotation() const {
    return annotation;
}

void Book::setAnnotation(const std::string &annotation) {
    Book::annotation = annotation;
}

const std::string &Book::getDate() const {
    return date;
}

void Book::setDate(const std::string &date) {
    Book::date = date;
}

const std::vector<std::string> &Book::getAuthors() const {
    return *authors;
}

void Book::setAuthors(std::vector<std::string> *authors) {
    Book::authors = authors;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << '(' << book.name << ", " << book.pages << ", " << book.annotation << ", "
       << book.date << ", " << '{';

    for(int i = 0; i < book.authors->size(); i++){
        os << book.authors->operator[](i) << ' ';
    }
    os << '}' << ')';
    return os;
}

bool Book::operator==(const Book &rhs) const {
    return name == rhs.name &&
           pages == rhs.pages &&
           annotation == rhs.annotation &&
           date == rhs.date &&
           authors == rhs.authors;
}

bool Book::operator!=(const Book &rhs) const {
    return !(rhs == *this);
}

bool Book::operator<(const Book &rhs) const {
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    if (pages < rhs.pages)
        return true;
    if (rhs.pages < pages)
        return false;
    if (annotation < rhs.annotation)
        return true;
    if (rhs.annotation < annotation)
        return false;
    if (date < rhs.date)
        return true;
    if (rhs.date < date)
        return false;
    return authors < rhs.authors;
}

bool Book::operator>(const Book &rhs) const {
    return rhs < *this;
}

bool Book::operator<=(const Book &rhs) const {
    return !(rhs < *this);
}

bool Book::operator>=(const Book &rhs) const {
    return !(*this < rhs);
}