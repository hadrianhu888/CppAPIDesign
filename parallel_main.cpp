/**
 * @file parallel_main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <string>
#include <vector>
#include <thread>
#include "parallel.cpp"
#include <iostream> 

int main(int argc, char **argv) {
    StringEncryptor encryptor;
    encryptor.SetKey("secretkey");
    std::vector<std::string> messages = {"Hello", "World"};
    std::vector<std::thread> threads;
    for (std::string message : messages) {
    threads.push_back(std::thread([&encryptor, message] {
		std::string encrypted = encryptor.Encrypt(message);
		std::cout << encrypted << std::endl;
	}));
        }

        for (std::thread &thread : threads) {
            thread.join();
        }
    // prints out some informational text
    std::cout << "All messages encrypted in parallel threads!" << std::endl;
    // decrypt the message
    std::cout << "Decrypted messages: " << std::endl;
    for (std::string message : messages) {
            std::string decrypted = encryptor.Decrypt(message);
            std::cout << decrypted << std::endl;
        }
    return 0;
}