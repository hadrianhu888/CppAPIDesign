#include "Proxy.h"

// Default constructor
Proxy::Proxy() {
  this->ip = "";
  this->port = 0;
}

// Parameterized constructor
Proxy::Proxy(std::string ip, int port) {
  this->ip = ip;
  this->port = port;
}

// Destructor
Proxy::~Proxy() {
  // Cleanup code here if needed
}

// Setters and getters for data
void Proxy::set_data(std::string data) { this->data = data; }

std::string Proxy::get_data() { return this->data; }

// Setters and getters for ip
void Proxy::set_ip(std::string ip) { this->ip = ip; }

std::string Proxy::get_ip() { return this->ip; }

// Setters and getters for port
void Proxy::set_port(int port) { this->port = port; }

int Proxy::get_port() { return this->port; }

// Setters and getters for connected
void Proxy::set_connected(bool connected) {
  // Your implementation here
}

bool Proxy::get_connected() {
  // Your implementation here
  return false;
}

// Setters and getters for closed
void Proxy::set_closed(bool closed) {
  // Your implementation here
}

bool Proxy::get_closed() {
  // Your implementation here
  return false;
}

// Note that the pure virtual methods are not implemented here.
// They should be implemented in the derived classes.
