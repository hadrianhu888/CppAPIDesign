/**
 * @file TextChatLog.h
 * @brief Declaration of the TextChatLog class
 * @version 0.1
 * @date 2023-10-09
 */

#ifndef TEXTCHATLOG_H
#define TEXTCHATLOG_H

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>


class TextChatLog {
public:
  TextChatLog();
  ~TextChatLog();
  void send(std::string msg);
  void receive(std::string msg);
  std::vector<std::string> getMessages();

private:
  struct ChatEvent {
    std::string msg;
    bool is_new;
  };
  void run();
  void stop();
  void join();
  void setMsg(std::string msg, bool is_new);

  std::vector<ChatEvent> chatLog;
  std::mutex chatLogMutex;
  std::condition_variable chatLogCond;
  std::thread logThread;
};

#endif // TEXTCHATLOG_H
