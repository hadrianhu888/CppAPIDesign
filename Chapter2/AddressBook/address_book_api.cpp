/**
 * @file address_book_api.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "person_api.cpp"
#include <vector>
class AddressBook {
  private:
    std::vector<Person> people;

  public:
    AddressBook(){};
    void addPerson(Person person) { people.push_back(person); }
    std::vector<Person> getPeople() { return people; }
    void setPeople(std::vector<Person> people) { this->people = people; }
};

int address_main() {
    AddressBook book;
    Person person1("John", 30);
    person1.setAddress("123 Main St");
    person1.setPhone("555-1234");
    person1.setEmail("john@email.com");
    book.addPerson(person1);
    Person person2("Sara", 25);
    person2.setAddress("456 Oak Ave");
    person2.setPhone("555-5555");
    person2.setEmail("sara@email.com");
    book.addPerson(person2);
    Person person3("Bill", 35);
    person3.setAddress("789 Broadway");
    person3.setPhone("555-9999");
    person3.setEmail("bill@gmail.com");
    return 0;
}

