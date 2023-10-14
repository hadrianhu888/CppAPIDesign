/**
 * @file parallel.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>

class StringEncryptor
{
public:
    std::string Encrypt(const std::string& plain);
    void SetKey(const std::string& key);
    std::string Decrypt(const std::string& encrypted);

private:
    std::string key;
};


std::string Decrypt(const std::string& encrypted) {
    std::string decrypted;
    // decryption logic here
    return decrypted;
}

void StringEncryptor::SetKey(const std::string &key) { this->key = key; }

std::string StringEncryptor::Encrypt(const std::string &plain) {
    std::string encrypted;
    // encryption logic here using 'key' member variable
    return encrypted;
}

