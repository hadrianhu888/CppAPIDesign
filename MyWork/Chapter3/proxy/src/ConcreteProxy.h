#include "Proxy.h"

class ConcreteProxy : public Proxy {
public:
  void connect() override {
    // Implement the method
    int socket = 0;
    std::string ip = "";
    int port = 0;
    bool connected = true;
  }
  void disconnect() override {
    // Implement the method
    bool connected = false;
  }
  void send(std::string data) override {
    // Implement the method
    // send the data
    for (int i = 0; i < data.length(); i++) {
      std::cout << data[i];
    }
  }
  void receive() override {
    // Implement the method
    // receive the data
    std::string data = ConcreteProxy ::get_data();
    for (int i = 0; i < data.length(); i++) {
      std::cout << data[i];
    }
  }
  void close() override {
    // Implement the method
    bool closed = true;
  }
  void request() override {
    // Implement the method
    bool connected = true;
    bool closed = false;
    while (connected && !closed) {
      std::string data = ConcreteProxy ::get_data();
      ConcreteProxy ::send(data);
      ConcreteProxy ::receive();
    }
  }
  void response() override {
    // Implement the method
    bool connected = true;
    bool closed = false;
    while (connected && !closed) {
      std::string data = ConcreteProxy ::get_data();
      ConcreteProxy ::send(data);
      ConcreteProxy ::receive();
    }
  }
};
