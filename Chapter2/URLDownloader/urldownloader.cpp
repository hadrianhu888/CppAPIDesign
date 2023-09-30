
#if defined(_WIN32) || defined(_WIN64)
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCKAPI_
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <windows.h>
#elif defined(__CYGWIN__)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#elif defined(__linux__) || defined(__APPLE__)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#endif

#include "URLDownloader.h"
#include <string>
#include <sstream>

// ... rest of the code


// rest of the code

URLDownloader::URLDownloader(std::string url) { this->url = url; }

std::string URLDownloader::getData() { return data; }

void URLDownloader::download() {
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL, *ptr = NULL, hints;
    
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        // Handle error
        return;
    }
    
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    
    // Resolve the server address and port
    if (getaddrinfo(url.c_str(), "80", &hints, &result) != 0) {
        // Handle error
        WSACleanup();
        return;
    }
    
    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            continue;
        }
        
        if (connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen) == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }
    
    if (ConnectSocket == INVALID_SOCKET) {
        // Handle error
        freeaddrinfo(result);
        WSACleanup();
        return;
    }
    
    freeaddrinfo(result);

    // ... (rest of the code remains unchanged)
}
