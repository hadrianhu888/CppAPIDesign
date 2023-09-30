/**
 * @file address_book_api.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include "address_book_api.h"

AddressBook::AddressBook(std::string name, int age) {
    this->name = name;
    this->age = age;
    this->id = 1;
    std::cout << "AddressBook: " << name << ", " << age << std::endl;
    std::cout << "AddressBook: " << address << std::endl;
    std::cout << "AddressBook: " << phone << std::endl;
    std::cout << "AddressBook: " << email << std::endl;
    std::cout << "AddressBook: " << id << std::endl;
}

std::string AddressBook::getName() {
  return name;
}

int AddressBook::getAge() { return age; }

std::string AddressBook::getAddress() { return address; }

void AddressBook::setAddress(std::string address) { this->address = address; }

std::string AddressBook::getPhone() { return phone; }

void AddressBook::setPhone(std::string phone) { this->phone = phone; }

std::string AddressBook::getEmail() { return email; }

void AddressBook::setEmail(std::string email) { this->email = email; }

int AddressBook::getId() { return id; }

void AddressBook::setId(int id) { this->id = id; }

void AddressBook::print() { std::cout << "AddressBook: " << name << ", " << age << std::endl; }

void AddressBook::printPerson() {
  std::cout << "AddressBook: " << name << ", " << age << std::endl;
    std::cout << "AddressBook: " << address << std::endl;
    std::cout << "AddressBook: " << phone << std::endl;
    std::cout << "AddressBook: " << email << std::endl;
}

void AddressBook::printPerson(Person person) {
  std::cout << "AddressBook: " << name << ", " << age << std::endl;
    std::cout << "AddressBook: " << address << std::endl;
    std::cout << "AddressBook: " << phone << std::endl;
    std::cout << "AddressBook: " << email << std::endl;
}

void AddressBook::printPerson(Person *person) {
  std::cout << "AddressBook: " << name << ", " << age << std::endl;
    std::cout << "AddressBook: " << address << std::endl;
    std::cout << "AddressBook: " << phone << std::endl;
    std::cout << "AddressBook: " << email << std::endl;
}

