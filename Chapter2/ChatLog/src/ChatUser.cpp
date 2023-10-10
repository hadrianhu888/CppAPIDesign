#include "ChatUser.h"

ChatUser::ChatUser(std::string name) : name(name), is_running(true) {
  thread = std::thread(&ChatUser::run, this);
}

ChatUser::~ChatUser() {
  stop();
  join();
}

void ChatUser::send(std::string msg) {
  std::lock_guard<std::mutex> lock(mtx);
  msgs.push_back(msg);
  cv.notify_all();
}

void ChatUser::receive(std::string msg) {
  std::lock_guard<std::mutex> lock(mtx);
  new_msgs.push_back(msg);
}

void ChatUser::run() {
  while (is_running) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this] { return !msgs.empty() || !new_msgs.empty(); });

    for (const auto &msg : msgs) {
      setMsg(msg, false);
    }
    msgs.clear();

    for (const auto &msg : new_msgs) {
      setMsg(msg, true);
    }
    new_msgs.clear();
  }
}

void ChatUser::stop() {
  is_running = false;
  cv.notify_all();
}

void ChatUser::join() {
  if (thread.joinable()) {
    thread.join();
  }
}

std::string ChatUser::getName() { return name; }

std::string ChatUser::getMsg() {
  std::lock_guard<std::mutex> lock(mtx);
  return msg;
}

void ChatUser::setMsg(std::string msg) {
  std::lock_guard<std::mutex> lock(mtx);
  this->msg = msg;
}

void ChatUser::setMsg(std::string msg, bool is_new) {
  std::string formatted_msg = is_new ? "New: " + msg : "Received: " + msg;
  setMsg(formatted_msg);
}
