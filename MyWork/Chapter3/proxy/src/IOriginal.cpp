/**
 * @file IOriginal.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "IOriginal.h"

// Constructor
IOriginal::IOriginal(Proxy *proxy) : Proxy(proxy->get_ip(), proxy->get_port()) {
  this->proxy = proxy;
  // Initialize other attributes if necessary
}

// Destructor
IOriginal::~IOriginal() {
  // Release resources if any
  this->proxy = nullptr;
}

// Implementing overridden functions
void IOriginal::connect() {
  // Your implementation here
  this->proxy->connect();
}

void IOriginal::disconnect() {
  // Your implementation here
  this->proxy->disconnect();
}

void IOriginal::send(std::string data) {
  // Your implementation here
  this->proxy->send(data);
}

void IOriginal::receive() {
  // Your implementation here
  this->proxy->receive();
}

void IOriginal::close() {
  // Your implementation here
  this->proxy->close();
}

// Setters and Getters
void IOriginal::set_data(std::string data) { this->data = data; }

std::string IOriginal::get_data() { return this->data; }

void IOriginal::set_ip(std::string ip) { this->ip = ip; }

std::string IOriginal::get_ip() { return this->ip; }

void IOriginal::set_port(int port) { this->port = port; }

int IOriginal::get_port() { return this->port; }

void IOriginal::set_socket(int socket) { this->socket = socket; }

int IOriginal::get_socket() { return this->socket; }

void IOriginal::set_connected(bool connected) { this->connected = connected; }

bool IOriginal::get_connected() { return this->connected; }

void IOriginal::set_closed(bool closed) { this->closed = closed; }

bool IOriginal::get_closed() { return this->closed; }

// Additional Methods
void IOriginal::request(IOriginal *original, std::string data) {
  original->set_data(data);
  original->connect();
  original->send(original->get_data());
  original->receive();
  original->close();
}

void IOriginal::response(IOriginal *orignal, std::string data) {
  orignal->set_data(data);
  orignal->connect();
  orignal->send(orignal->get_data());
  orignal->receive();
  orignal->close();
}
