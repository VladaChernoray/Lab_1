#include "Character.h"

Character::Role::Role(Book *book, Character::Role::Part part) : book(book), part(part) {}

Book *Character::Role::getBook() const {
    return book;
}

void Character::Role::setBook(Book *book) {
    Role::book = book;
}

Character::Role::Part Character::Role::getPart() const {
    return part;
}

void Character::Role::setPart(Character::Role::Part part) {
    Role::part = part;
}

std::ostream &operator<<(std::ostream &os, const Character::Role &role) {
    os << "{" << *role.book << ", " << role.part << '}';
    return os;
}

bool Character::Role::operator==(const Character::Role &rhs) const {
    return book == rhs.book &&
           part == rhs.part;
}

bool Character::Role::operator!=(const Character::Role &rhs) const {
    return !(rhs == *this);
}

bool Character::Role::operator<(const Character::Role &rhs) const {
    if (book < rhs.book)
        return true;
    if (rhs.book < book)
        return false;
    return part < rhs.part;
}

bool Character::Role::operator>(const Character::Role &rhs) const {
    return rhs < *this;
}

bool Character::Role::operator<=(const Character::Role &rhs) const {
    return !(rhs < *this);
}

bool Character::Role::operator>=(const Character::Role &rhs) const {
    return !(*this < rhs);
}

Character::Character(std::vector<std::string> *names,
                     std::vector<Role> *roles = new std::vector<Role>) :
        names(names), roles(roles) {}

Character::Character(std::string name1, std::string name2, std::string name3) {
    names = new std::vector<std::string>;
    names->push_back(name1);
    if (!name2.empty())
        names->push_back(name2);
    if (!name3.empty())
        names->push_back(name3);

    roles = new std::vector<Role>;
}

void Character::add_name(const std::string &name) {
    Character::names->push_back(name);
}

void Character::add_role(Character::Role role) {
    Character::roles->push_back(role);
}

std::vector<std::string> *Character::getNames() const {
    return names;
}

void Character::setNames(std::vector<std::string> *names) {
    Character::names = names;
}

std::vector<Character::Role> *Character::getRoles() const {
    return roles;
}

void Character::setRoles(std::vector<Role> *roles) {
    Character::roles = roles;
}

std::ostream &operator<<(std::ostream &os, const Character &character) {
    os << '{' << '{';
    if (character.names->size() != 0) {
        for (int i = 0; i < character.names->size() - 1; i++) {
            os << character.names->operator[](i) << ", ";
        }
        os << character.names->operator[](character.names->size() - 1);
    }
    os << "}, {";

    if (character.roles->size() != 0) {
        for (int i = 0; i < character.roles->size() - 1; i++) {
            os << character.roles->operator[](i) << ", ";
        }
        os << character.roles->operator[](character.roles->size() - 1);
    }
    os << "}}";
    return os;
}

bool Character::operator==(const Character &rhs) const {
    return names == rhs.names &&
           roles == rhs.roles;
}

bool Character::operator!=(const Character &rhs) const {
    return !(rhs == *this);
}

bool Character::operator<(const Character &rhs) const {
    if (names < rhs.names)
        return true;
    if (rhs.names < names)
        return false;
    return roles < rhs.roles;
}

bool Character::operator>(const Character &rhs) const {
    return rhs < *this;
}

bool Character::operator<=(const Character &rhs) const {
    return !(rhs < *this);
}

bool Character::operator>=(const Character &rhs) const {
    return !(*this < rhs);

}