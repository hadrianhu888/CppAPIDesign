/**
 * @file Proxy.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef PROXY_H
#define PROXY_H

#include <iostream>

class Proxy {
public:
  Proxy();
  Proxy(std::string ip, int port);
  ~Proxy();
  virtual void connect() = 0;
  virtual void disconnect() = 0;
  virtual void send(std::string data) = 0;
  virtual void receive() = 0;
  virtual void close() = 0;
  void set_data(std::string data);
  std::string get_data();
  void set_ip(std::string ip);
  std::string get_ip();
  void set_port(int port);
  int get_port();
  void set_socket(int socket);
  int get_socket();
  void set_connected(bool connected);
  bool get_connected();
  void set_closed(bool closed);
  bool get_closed();
  virtual void request(void) = 0;
  virtual void response(void) = 0;

private:
  std::string ip;
  int port;
  std::string data;
};

#endif // PROXY_H