/**
 * @file ChatUser.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CHATUSER_H
#define CHATUSER_H

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

class ChatUser {
public:
  ChatUser(std::string name);
  ~ChatUser();
  void send(std::string msg);
  void receive(std::string msg);
  void run();
  void stop();
  void join();
  std::string getName();
  std::string getMsg();
  void setMsg(std::string msg);
  void setMsg(std::string msg, bool is_new);

private:
  std::string name;
  std::string msg;
  std::mutex mtx;
  std::condition_variable cv;
  std::atomic<bool> is_running;
  std::thread thread;
  std::vector<std::string> msgs;
  std::vector<std::string> new_msgs;
  std::vector<std::string>::iterator it;
  std::vector<std::string>::iterator it_end;
  std::vector<std::string>::iterator it_new;
};

#endif // CHATUSER_H