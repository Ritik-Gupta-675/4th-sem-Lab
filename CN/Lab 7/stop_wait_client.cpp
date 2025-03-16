#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstring>
#include <windows.h> 

using namespace std;
#pragma comment(lib, "Ws2_32.lib")
void waitForAck(int sock) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        cout << "Received ACK from server." << endl;
    } else {
        cout << "No ACK received. Resending frame..." << endl;
    }
}

int main() {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        cout << "WSAStartup failed: " << iResult << endl;
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cout << "Socket creation failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cout << "Connection failed: " << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    string frames[] = {"Frame1", "Frame2", "Frame3", "Frame4"};
    for (const auto& frame : frames) {
        cout << "Sending: " << frame << endl;
        send(sock, frame.c_str(), frame.length(), 0);
        
        waitForAck(sock);
        Sleep(1000); 
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
