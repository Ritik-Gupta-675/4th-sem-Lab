#include <iostream>
using namespace std;
int getParityBitsCount(int dataBits) {
    int r = 0;
    while ((1 << r) < (dataBits + r + 1)) {
        r++;
    }
    return r;
}
void generateHammingCode(string data) {
    int dataBits = data.length();
    int parityBits = getParityBitsCount(dataBits);
    int totalBits = dataBits + parityBits;
    char hammingCode[totalBits + 1];
    int j = 0;
    for (int i = 1; i <= totalBits; i++) {
        if ((i & (i - 1)) == 0) {
            hammingCode[i] = '0'; 
        } else {
            hammingCode[i] = data[j++];
        }
    }
    for (int i = 0; i < parityBits; i++) {
        int position = (1 << i);
        int parity = 0;
        for (int k = position; k <= totalBits; k++) {
            if (k & position) {
                parity ^= (hammingCode[k] - '0');
            }
        }
        hammingCode[position] = parity + '0';
    }
    cout << "Hamming Code: ";
    for (int i = 1; i <= totalBits; i++) {
        cout << hammingCode[i];
    }
    cout << endl;
}
int main() {
    string data = "1011";
    cout << "Original Data: " << data << endl;
    generateHammingCode(data);
    return 0;
}