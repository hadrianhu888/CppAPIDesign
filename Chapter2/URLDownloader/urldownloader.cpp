/**
 * @file urldownloader.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

include_directories("E:/GitHubRepos/vcpkg/installed/x64-windows/include/curl")

class URLDownloader {
    private:
        string url;
        string data;
        static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    public:
        URLDownloader(string url);
        string getData();
        void download();
};

URLDownloader::URLDownloader(string url) { this->url = url; }

string URLDownloader::getData() { return data; }

void URLDownloader::download() {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

size_t URLDownloader::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, char **argv) {
    URLDownloader downloader("https://www.google.com");
    downloader.download();
    cout << downloader.getData() << endl;
    return 0;
}

