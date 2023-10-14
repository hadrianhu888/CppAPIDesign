/**
 * @file autotimer.cpp
 * @brief Implementation of AutoTimer class methods
 * @version 0.1
 * @date 2023-10-14
 *
 */

#include "autotimer.h"

class AutoTimer::impl {
public:
  std::mutex mtx;
  std::chrono::milliseconds duration;
  std::string name;
  std::string description;
  std::chrono::time_point<std::chrono::system_clock> start_time;
};

AutoTimer::AutoTimer(const std::chrono::milliseconds &duration)
    : pimpl(new impl()) {
  pimpl->duration = duration;
  m_running = false;
}

AutoTimer::AutoTimer(const std::string &name,
                     const std::chrono::milliseconds &duration)
    : pimpl(new impl()) {
  pimpl->name = name;
  pimpl->duration = duration;
  m_running = false;
}

AutoTimer::AutoTimer(const std::string &name, const std::string &description,
                     const std::chrono::milliseconds &duration)
    : pimpl(new impl()) {
  pimpl->name = name;
  pimpl->description = description;
  pimpl->duration = duration;
  m_running = false;
}

AutoTimer::AutoTimer() : pimpl(new impl()), m_running(false) {}

AutoTimer::~AutoTimer() { delete pimpl; }

void AutoTimer::start() {
  std::lock_guard<std::mutex> lock(pimpl->mtx);
  if (!m_running) {
    m_start = std::chrono::system_clock::now();
    m_running = true;
  }
}

void AutoTimer::stop() {
  std::lock_guard<std::mutex> lock(pimpl->mtx);
  if (m_running) {
    auto end = std::chrono::system_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - m_start);
    if (elapsed >= pimpl->duration) {
      // Do something with the elapsed time
      std::cout << "Timer '" << pimpl->name
                << "' exceeded the specified duration." << std::endl;
    }
    m_running = false;
  }
}

AutoTimer::AutoTimer(const std::string &name)
    : AutoTimer(name, std::chrono::milliseconds(0)) {}
