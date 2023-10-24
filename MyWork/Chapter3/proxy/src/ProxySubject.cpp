/**
 * @file ProxySubject.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "ProxySubject.h"
#include "Proxy.h"

// Constructor
ProxySubject::ProxySubject(Proxy *proxy)
    : Proxy(proxy->get_ip(), proxy->get_port()) {
  // Initialize other attributes if necessary
  this->ip = "127.0.0.1";
  this->port = 8080;
}

// Destructor
ProxySubject::~ProxySubject() {
  // Release resources if any
  this->proxy = nullptr;
  this->ip = "";
}

// Overridden Methods
void ProxySubject::connect() {
  // Your implementation here
  this->proxy->connect();
}

void ProxySubject::disconnect() {
  // Your implementation here
  this->proxy->disconnect();
}

void ProxySubject::send(std::string data) {
  // Your implementation here
  this->proxy->send(data);
}

void ProxySubject::receive() {
  // Your implementation here
  this->proxy->receive();
}

void ProxySubject::close() {
  // Your implementation here
  this->proxy->close();
}

// Setters and Getters
void ProxySubject::set_data(std::string data) { this->data = data; }

std::string ProxySubject::get_data() { return this->data; }

void ProxySubject::set_ip(std::string ip) { this->ip = ip; }

std::string ProxySubject::get_ip() { return this->ip; }

void ProxySubject::set_port(int port) { this->port = port; }

int ProxySubject::get_port() { return this->port; }

void ProxySubject::set_socket(int socket) { this->socket = socket; }

int ProxySubject::get_socket() { return this->socket; }

void ProxySubject::set_connected(bool connected) {
  this->connected = connected;
}

bool ProxySubject::get_connected() { return this->connected; }

void ProxySubject::set_closed(bool closed) { this->closed = closed; }

bool ProxySubject::get_closed() { return this->closed; }

// Additional Methods
void ProxySubject::request(void) {
  this->proxy->request();
  this->proxy->receive();
  this->proxy->response();
  this->proxy->send(this->data);
  this->proxy->receive();
}

void ProxySubject::response(void) {
  this->proxy->response();
  this->proxy->send(this->data);
  this->proxy->receive();
  this->proxy->request();
  this->proxy->receive();
  this->proxy->close();
}