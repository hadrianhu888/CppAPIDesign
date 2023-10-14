/**
 * @file TextChatLog.cpp
 * @brief Implementation of the TextChatLog class
 * @version 0.1
 * @date 2023-10-09
 */

#include "TextChatLog.h"

#include <algorithm>
#include <cassert>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

TextChatLog::TextChatLog() {
  // Initialize any necessary data structures or variables
  logThread = std::thread(&TextChatLog::run, this);
  chatLog.reserve(100);
}

TextChatLog::~TextChatLog() {
  // Clean up any allocated memory or resources
  stop();
  join();
}

void TextChatLog::send(std::string msg) {
  // Create a new chat event and set the message as sent
  setMsg(msg, false);
}

void TextChatLog::receive(std::string msg) {
  // Create a new chat event and set the message as received
  setMsg(msg, true);
}

std::vector<std::string> TextChatLog::getMessages() {
  std::vector<std::string> messages;
  std::lock_guard<std::mutex> lock(chatLogMutex);
  for (const auto &event : chatLog) {
    if (event.is_new) {
      // Add the received message to the result vector
      messages.push_back(event.msg);
    }
  }
  return messages;
}

void TextChatLog::run() {
  // Run the chat log
  while (true) {
    std::unique_lock<std::mutex> lock(chatLogMutex);
    chatLogCond.wait(lock, [this]() { return !chatLog.empty(); });

    // Check for new messages
    std::vector<std::string> messages = getMessages();
    lock.unlock();

    if (!messages.empty()) {
      // Print the messages
      for (const auto &msg : messages) {
        std::cout << msg << std::endl;
      }
    }

    // Sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void TextChatLog::stop() {
  // Stop the chat log
  chatLogCond.notify_one();
}

void TextChatLog::join() {
  // Wait for the chat log thread to finish
  if (logThread.joinable()) {
    logThread.join();
  }
}

void TextChatLog::setMsg(std::string msg, bool is_new) {
  // Create a new chat event and add it to the chat log
  ChatEvent event{msg, is_new};
  std::lock_guard<std::mutex> lock(chatLogMutex);
  chatLog.push_back(event);
  chatLogCond.notify_one();
}
