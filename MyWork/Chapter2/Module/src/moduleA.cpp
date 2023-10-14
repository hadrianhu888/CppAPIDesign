#include "ModuleA.h"

namespace moduleA {

ModuleA::ModuleA(Callback callback) {
  // Set the callback
  set_callback(callback);
}

void ModuleA::send(std::string msg) {
  std::cout << "Sending message: " << msg << std::endl;
}

void ModuleA::receive(std::string msg) {
  std::cout << "Received message: " << msg << std::endl;
}

void ModuleA::start() { std::cout << "ModuleA started." << std::endl; }

void ModuleA::stop() { std::cout << "ModuleA stopped." << std::endl; }

void ModuleA::run() { std::cout << "ModuleA is running." << std::endl; }

ModuleA::~ModuleA() { std::cout << "ModuleA destroyed." << std::endl; }

void ModuleA::wait() {
  std::unique_lock<std::mutex> lock(cv_mutex_);
  cv_.wait(lock);
}

void ModuleA::notify() { cv_.notify_one(); }

void ModuleA::notify_all() { cv_.notify_all(); }

void ModuleA::set_callback(Callback callback) {
  std::cout << "Callback set." << std::endl;
}

void ModuleA::set_callback(void *callback) {
  std::cout << "Callback set using void pointer." << std::endl;
}

} // namespace moduleA
