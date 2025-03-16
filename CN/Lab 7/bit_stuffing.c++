#include <iostream>
#include <vector>
using namespace std;

vector<int> bitStuffing(vector<int> &data) {
    vector<int> stuffed;
    int count = 0;
    
    for (int bit : data) {
        stuffed.push_back(bit);
        if (bit == 1) {
            count++;
            if (count == 5) { 
                stuffed.push_back(0);
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return stuffed;
}
vector<int> bitDestuffing(vector<int> &stuffed) {
    vector<int> destuffed;
    int count = 0;
    
    for (size_t i = 0; i < stuffed.size(); i++) {
        destuffed.push_back(stuffed[i]);
        if (stuffed[i] == 1) {
            count++;
            if (count == 5 && i + 1 < stuffed.size() && stuffed[i + 1] == 0) {
                i++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return destuffed;
}

int main() {
    vector<int> data = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0};
    cout << "Original Data: ";
    for (int bit : data) {
        cout << bit << " ";
    }
    cout << endl;
    vector<int> stuffed = bitStuffing(data);
    cout << "Stuffed Data: ";
    for (int bit : stuffed) {
        cout << bit << " ";
    }
    cout << endl;
    vector<int> destuffed = bitDestuffing(stuffed);
    cout << "Destuffed Data: ";
    for (int bit : destuffed) {
        cout << bit << " ";
    }
    cout << endl;
    
    return 0;
}