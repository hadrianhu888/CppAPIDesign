#include "TextChatLog.h"

TextChatLog::TextChatLog() : is_running(true) {
  thread = std::thread(&TextChatLog::run, this);
}

TextChatLog::~TextChatLog() {
  stop();
  join();
}

void TextChatLog::send(std::string msg) {
  std::lock_guard<std::mutex> lock(mtx);
  msgs.push_back(msg);
  cv.notify_all();
}

void TextChatLog::receive(std::string msg) {
  std::lock_guard<std::mutex> lock(mtx);
  new_msgs.push_back(msg);
}

void TextChatLog::run() {
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

void TextChatLog::stop() {
  is_running = false;
  cv.notify_all();
}

void TextChatLog::join() {
  if (thread.joinable()) {
    thread.join();
  }
}

std::vector<std::string> TextChatLog::getMessages() {
  std::lock_guard<std::mutex> lock(mtx);
  return messages;
}

void TextChatLog::setMsg(std::string msg, bool is_new) {
  std::string formatted_msg = is_new ? "New: " + msg : "Received: " + msg;
  messages.push_back(formatted_msg);
}
