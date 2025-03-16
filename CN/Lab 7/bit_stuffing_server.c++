#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")
string bitDestuff(const string &input) {
    string output = "";
    int count = 0;
    for (size_t i = 0; i < input.size(); i++) {
        char bit = input[i];
        output.push_back(bit);
        if (bit == '1') {
            count++;
            if (count == 5) {
                i++; 
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return output;
}

int main() {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        cout << "WSAStartup failed: " << iResult << endl;
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        cout << "Socket creation failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Bind failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, 3) == SOCKET_ERROR) {
        cout << "Listen failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    
    cout << "Server listening on port 8080..." << endl;
    SOCKET clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        cout << "Accept failed: " << WSAGetLastError() << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    char buffer[1024] = {0};
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived == SOCKET_ERROR) {
        cout << "Receive failed: " << WSAGetLastError() << endl;
    } else {
        string stuffedData(buffer, bytesReceived);
        cout << "Received Stuffed Data: " << stuffedData << endl;

        string originalData = bitDestuff(stuffedData);
        cout << "Recovered Original Data: " << originalData << endl;
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    
    return 0;
}