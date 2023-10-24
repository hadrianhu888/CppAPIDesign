
#include "ConcreteProxy.h"
#include "Proxy.h"
#include "ProxySubject.h"
#include "RealSubject.h"

int main(int argc, char **argv) {
  // Create a proxy
  ConcreteProxy *proxy = new ConcreteProxy();

  // Create a proxy subject
  ProxySubject *proxy_subject = new ProxySubject(proxy);

  // Create a real subject
  RealSubject *real_subject = new RealSubject(proxy);

  // Connect the proxy subject to the real subject
  proxy_subject->connect();

  // Send data to the real subject
  real_subject->send("Hello World!");

  // Receive data from the real subject
  real_subject->receive();

  // Disconnect the proxy subject from the real subject
  proxy_subject->disconnect();

  // Delete the proxy subject
  proxy_subject = nullptr;

  // Delete the real subject
  real_subject = nullptr;

  // Delete the proxy
  proxy = nullptr;

  return 0;
}
