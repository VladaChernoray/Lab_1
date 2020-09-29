#ifndef LAB_1_BOOK_H
#define LAB_1_BOOK_H

#include <vector>
#include <string>
#include <ostream>


class Book {
private:
    std::string name;
    int pages;
    std::string annotation;
    std::string date;
    std::vector<std::string> *authors;

public:

    Book();

    Book(std::string name,
         int pages,
         std::string annotation,
         std::string date,
         std::vector<std::string> *authors);

    Book(std::string name,
         int pages = 0,
         std::string annotation = "no annotation",
         std::string date = "0000.00.00",
         const std::string& author1 = "noname author",
         const std::string& author2 = "",
         const std::string& author3 = "");

    const std::string &getName() const;

    void setName(const std::string &name);

    int getPages() const;

    void setPages(int pages);

    const std::string &getAnnotation() const;

    void setAnnotation(const std::string &annotation);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    const std::vector<std::string> &getAuthors() const;

    void setAuthors(std::vector<std::string> *authors);

    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    bool operator==(const Book &rhs) const;

    bool operator!=(const Book &rhs) const;

    bool operator<(const Book &rhs) const;

    bool operator>(const Book &rhs) const;

    bool operator<=(const Book &rhs) const;

    bool operator>=(const Book &rhs) const;
};

#endif //LAB_1_BOOK_H
