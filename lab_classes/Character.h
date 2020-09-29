#ifndef LAB_1_CHARACTER_H
#define LAB_1_CHARACTER_H

#include <ostream>
#include "Book.h"

class Character {
public:
    class Role{
    public:
        enum Part{
            MAIN,
            MINOR,
            EPISODIC,
            NONE
        };
    private:
        Book* book;
        Part part;

    public:
        Role(Book *book, Part part);

        Book *getBook() const;

        void setBook(Book *book);

        Part getPart() const;

        void setPart(Part part);

        bool operator<(const Role &rhs) const;

        bool operator>(const Role &rhs) const;

        bool operator<=(const Role &rhs) const;

        bool operator>=(const Role &rhs) const;

        bool operator==(const Role &rhs) const;

        bool operator!=(const Role &rhs) const;

        friend std::ostream &operator<<(std::ostream &os, const Role &role);
    };

private:
    std::vector<std::string> *names;
    std::vector<Role> *roles;

public:
    Character(std::vector<std::string> *names, std::vector<Role> *roles);

    Character(std::string name1, std::string name2 = "", std::string name3 = "");

    void add_name(const std::string& name);

    void add_role(Role role);

    std::vector<std::string> *getNames() const;

    void setNames(std::vector<std::string> *names);

    std::vector<Role> *getRoles() const;

    void setRoles(std::vector<Role> *roles);

    friend std::ostream &operator<<(std::ostream &os, const Character &character);

    bool operator==(const Character &rhs) const;

    bool operator!=(const Character &rhs) const;

    bool operator<(const Character &rhs) const;

    bool operator>(const Character &rhs) const;

    bool operator<=(const Character &rhs) const;

    bool operator>=(const Character &rhs) const;
};


#endif //LAB_1_CHARACTER_H
