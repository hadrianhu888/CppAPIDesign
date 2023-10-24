/**
 * @file IOriginal.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef IORIGINAL_H
#define IORIGINAL_H

#include <iostream>

#include "Proxy.h"

class IOriginal : public Proxy {
public:
  IOriginal(Proxy *proxy);
  ~IOriginal();
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
  void request(IOriginal *original, std::string data);
  void response(IOriginal *original, std::string data);

private:
  std::string ip;
  int port;
  std::string data;
  int socket;
  bool connected;
  Proxy *proxy;
  bool closed;
};

#endif // IORIGINAL_H