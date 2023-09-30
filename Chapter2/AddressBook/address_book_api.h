/**
 * @file address_book_api.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ADDRESS_BOOK_API_H
#define ADDRESS_BOOK_API_H

#include <string>

namespace address_book {
    class AddressBookAPI {
    private:
        std::string url;
        std::string data;
    public:
        AddressBookAPI(std::string url);
        std::string getData();
        void download();
        ~AddressBookAPI();
        void setName(std::string name);
        void setEmail(std::string email);
        void setPhone(std::string phone);
        void setAddress(std::string address);
        void setCity(std::string city);
        void setID(std::string id);
        void setCountry(std::string country);
        void setNotes(std::string notes);
        void setURL(std::string url);
        std::string getName();
        std::string getEmail();
        std::string getPhone();
        std::string getAddress();
        std::string getCity();
        std::string getID();
        std::string getCountry();
        std::string getNotes();
        std::string getURL();
        std::string getNotes();
        std::string getURL();
        std::string getNotes();
        std::string getURL();
    };
} // namespace address_book

#endif // ADDRESS_BOOK_API_H

// Path: Chapter2/AddressBook/address_book_api.cpp