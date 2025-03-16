#include <iostream>
#include <string>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

string bitStuff(const string &input) {
    string output = "";
    int count = 0;
    for (char bit : input) {
        output.push_back(bit);
        if (bit == '1') {
            count++;
            if (count == 5) {
                output.push_back('0');
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return output;
}

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        cout << "WSAStartup failed: " << iResult << endl;
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cout << "Socket creation error: " << WSAGetLastError() << endl;
        WSACleanup();
        return -1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        cout << "Connection failed: " << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    string data = "1010111111";
    cout << "Original Data: " << data << endl;
    string stuffedData = bitStuff(data);
    cout << "Stuffed Data: " << stuffedData << endl;

    send(sock, stuffedData.c_str(), stuffedData.length(), 0);
    cout << "Data sent to server." << endl;

    closesocket(sock);
    WSACleanup();
    return 0;
}
