/**
 * @file person_api.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * @brief Generates the person class as an API for any OS and language to use
 *
 */

#include <string>
#include <iostream>
class Person {
private:
	int id;
public:
    std::string name;
    int age;
    std::string address;
    std::string phone;
    std::string email;

    Person(std::string name, int age) {
		this->name = name;
		this->age = age;
    }
    std::string getName() {
		return name;
        }

    int getAge() { return age; }

    std::string getAddress() { return address; }
    void setAddress(std::string address) { this->address = address; }
    std::string getPhone() { return phone; }
    void setPhone(std::string phone) { this->phone = phone; }
    std::string getEmail() { return email; }
    void setEmail(std::string email) { this->email = email; }
    int getId() { return id; }
    void setId(int id) { this->id = id; }
};

int person_main() {
    Person person1("John", 30);
    std::cout << person1.getName() << " is " << person1.getAge() << std::endl;
    std::cout << "Address: " << person1.getAddress() << std::endl;
    person1.setAddress("123 Main St");
    std::cout << "New Address: " << person1.getAddress() << std::endl;
    person1.setPhone("555-1234");
    std::cout << "Phone: " << person1.getPhone() << std::endl;
    person1.setEmail("john@email.com");
    std::cout << "Email: " << person1.getEmail() << std::endl;
    return 0;
}