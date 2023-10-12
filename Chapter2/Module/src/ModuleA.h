/**
 * @file ModuleA.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MODULE_A_H
#define MODULE_A_H

#include <condition_variable>
#include <iostream>
#include <mutex>
namespace moduleA {
class ModuleA {
public:
  typedef void (*Callback)(void);
  ModuleA(Callback callback);
  void *thread_;
  std::condition_variable cv_;
  void send(std::string msg);
  void receive(std::string msg);
  void start();
  void stop();
  void run();
  ~ModuleA();
  void wait();
  void notify();
  void notify_all();
  void set_callback(Callback callback);
  void set_callback(void *callback);

private:
  typedef struct {
    std::string msg;
    std::mutex mutex;
    std::condition_variable cv;
    bool ready;
  } Message;
  std::mutex cv_mutex_;
}; // namespace moduleA
} // namespace moduleA
#endif // MODULE_A_H
