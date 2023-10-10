/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "main.h"

int main(int argc, char **argv) {
  TextChatLog chatLog;
  std::string msg;
  while (true) {
    std::cout << "Enter a message: ";
    std::cin >> msg;
    if (msg == "exit") {
      break;
      chatLog.send(msg);
      chatLog.receive(msg);
      chatLog.send(msg);
      chatLog.receive(msg);
      chatLog.send(msg);
      chatLog.receive(msg);
      chatLog.send(msg);
    }
  }
  return 0;
}
