/**
 * @file impl.cpp
 * @brief Implementation of impl class methods
 * @version 0.1
 * @date 2023-10-14
 *
 */

#include "impl.h"

void impl::start() {
  std::lock_guard<std::mutex> lock(m_mutex);
  m_start = std::chrono::system_clock::now();
}

void impl::stop() {
  std::lock_guard<std::mutex> lock(m_mutex);
  m_stop = std::chrono::system_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::milliseconds>(m_stop - m_start);
  std::cout << "Elapsed Time: " << elapsed.count() << " milliseconds"
            << std::endl;
}

impl::impl(const std::string &name, const std::string &description,
           const std::chrono::milliseconds &duration)
    : m_name(name), m_description(description) {}
