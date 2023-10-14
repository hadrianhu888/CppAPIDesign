/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "main.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

int main() {
  testChatUser();
  testTextChatLog();

  return 0;
}

void testChatUser() {
  ChatUser user1("Alice");
  ChatUser user2("Bob");

  user1.send("Hello, Bob!");
  user2.send("Hi, Alice!");

  user1.join();
  user2.join();
}

void testTextChatLog() {
  TextChatLog chatLog;

  chatLog.send("Message 1");
  chatLog.send("Message 2");
  chatLog.send("Message 3");

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  auto messages = chatLog.getMessages();

  for (const auto &msg : messages) {
    std::cout << msg << std::endl;
  }

  chatLog.send("Message 4");
  chatLog.send("Message 5");
  chatLog.send("Message 6");
  chatLog.send("Message 7");
  chatLog.send("Message 8");
  chatLog.send("Message 9");
  chatLog.send("Message 10");
}
