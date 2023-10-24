/**
 * @file RealSubject.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "Proxy.h"
#include "RealSubject.h"

// Constructor
RealSubject::RealSubject(Proxy *proxy)
    : Proxy(proxy->get_ip(), proxy->get_port()) {
  // Initialize other attributes if necessary
  this->ip = "127.0.0.1";
  this->port = 8080;
}

// Destructor
RealSubject::~RealSubject() {
  // Release resources if any
  this->proxy = nullptr;
  this->ip = "";
}

// Overridden Methods
void RealSubject::connect() {
  // Your implementation here
  this->proxy->connect();
}

void RealSubject::disconnect() {
  // Your implementation here
  this->proxy->disconnect();
}

void RealSubject::send(std::string data) {
  // Your implementation here
  this->proxy->send(data);
}

void RealSubject::receive() {
  // Your implementation here
  this->proxy->receive();
}

void RealSubject::close() {
  // Your implementation here
  this->proxy->close();
}

// Setters and Getters
void RealSubject::set_data(std::string data) { this->data = data; }

std::string RealSubject::get_data() { return this->data; }

void RealSubject::set_ip(std::string ip) { this->ip = ip; }

std::string RealSubject::get_ip() { return this->ip; }

void RealSubject::set_port(int port) { this->port = port; }

int RealSubject::get_port() { return this->port; }

void RealSubject::set_socket(int socket) { this->socket = socket; }

int RealSubject::get_socket() { return this->socket; }

void RealSubject::set_connected(bool connected) { this->connected = connected; }

bool RealSubject::get_connected() { return this->connected; }

void RealSubject::set_closed(bool closed) { this->closed = closed; }

bool RealSubject::get_closed() { return this->closed; }

// Additional Methods
void RealSubject::request(void) {
  this->proxy->request();
  this->proxy->receive();
  this->proxy->response();
  this->proxy->send(this->data);
  this->proxy->receive();
}

void RealSubject::response(void) {
  this->proxy->response();
  this->proxy->send(this->data);
  this->proxy->receive();
  this->proxy->request();
  this->proxy->receive();
  this->proxy->close();
}