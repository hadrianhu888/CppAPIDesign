#include <iostream>
#include "URLDownloader.h"

int main() {
    URLDownloader downloader("www.google.com");
    downloader.download();
    std::cout << downloader.getData() << std::endl;
    return 0;
}
