#include <iostream>
using namespace std;
void xorOperation(char* dividend, const char* divisor, int divisorLength) {
    for (int i = 0; i < divisorLength; i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}
string computeCRC(string data, string divisor) {
    int dataLength = data.length();
    int divisorLength = divisor.length();
    string dividend = data + string(divisorLength - 1, '0');
    for (int i = 0; i <= dataLength - 1; i++) {
        if (dividend[i] == '1') {
            xorOperation(&dividend[i], divisor.c_str(), divisorLength);
        }
    }
    return dividend.substr(dataLength, divisorLength - 1);
}
int main() {
    string data = "11010011101100"; 
    string divisor = "1011"; 
    
    cout << "Original Data: " << data << endl;
    cout << "Divisor: " << divisor << endl;
    
    string crc = computeCRC(data, divisor);
    cout << "CRC Checksum: " << crc << endl;
 
    string transmittedData = data + crc;
    cout << "Transmitted Data: " << transmittedData << endl;

    string remainder = computeCRC(transmittedData, divisor);
    if (remainder.find('1') == string::npos) {
        cout << "No error detected in received data."<<endl;
    } else {
        cout <<"Error detected in received data!"<<endl;
    }
    
    return 0;
}
