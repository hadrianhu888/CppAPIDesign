#ifndef URLDOWNLOADER_H
#define URLDOWNLOADER_H
#include <string>

class URLDownloader {
private:
  std::string url;
  std::string data;

public:
  URLDownloader(std::string url);
  std::string getData();
  void download();
};

#endif // URLDOWNLOADER_H
