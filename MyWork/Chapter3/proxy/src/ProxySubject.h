/**
 * @file ProxySubject.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PROXYSUBJECT_H
#define PROXYSUBJECT_H

#include <iostream>

#include "Proxy.h"

class ProxySubject : public Proxy {
public:
  ProxySubject(Proxy *proxy);
  ~ProxySubject();
  void connect() override;
  void disconnect() override;
  void send(std::string data) override;
  void receive() override;
  void close() override;
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
  void request(void) override;
  void response(void) override;

private:
  std::string ip;
  int port;
  std::string data;
  int socket;
  bool connected;
  Proxy *proxy;
  bool closed;
};

#endif // PROXYSUBJECT_H