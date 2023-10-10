/**
 * @file TextChatLog.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef TEXTCHATLOG_H
#define TEXTCHATLOG_H

#include "ChatUser.h"
#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

class TextChatLog {
public:
  TextChatLog();
  ~TextChatLog();
  void send(std::string msg);
  void receive(std::string msg);
  std::vector<std::string> getMessages();

private:
  void run();
  void stop();
  void join();
  void setMsg(std::string msg, bool is_new);

  std::mutex mtx;
  std::condition_variable cv;
  std::atomic<bool> is_running;
  std::thread thread;
  std::vector<std::string> msgs;
  std::vector<std::string> new_msgs;
  std::vector<std::string> messages;
};
#endif // TEXTCHATLOG_H
